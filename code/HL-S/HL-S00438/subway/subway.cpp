#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
bool viss[N],vist[N];
int c,n,m,w[N],z,d;
int a[510][30],k[500];
int b[N][510],l[N][30],cnt[N];
struct S{int n,t;};
S s;
queue<S> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> z;
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=1;i<=m;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j];
			cin >> b[a[i][j]][i];
			l[a[i][j]][++cnt[a[i][j]]]=i;
		}
	}
	for(int r=1;r<=z;r++){
		for(int i=1;i<=n;i++) viss[i]=false;
		for(int j=1;j<=m;j++) vist[j]=false;
		int x,y,mi=1e9+10;
		cin >> x >> y;
		s.n = x,s.t=w[x];
		q.push(s);
		while(!q.empty()){
			S now=q.front();
			if(now.n==y){
				mi=min(mi,now.t+w[y]);
			}
			for(int i=1;i<=cnt[now.n];i++){
				if(!vist[l[now.n][i]]){
					int ti=now.t + b[now.n][l[now.n][i]];
					for(int j=1;j<=k[j];j++){
						if(!viss[a[l[now.n][i]][j]]){
							s.n = a[l[now.n][i]][j];
							s.t = ti+b[a[l[now.n][i]][j]][l[now.n][i]];
							q.push(s);
							viss[a[l[now.n][i]][j]]=true;
						}
					}
					vist[l[now.n][i]]=true;
				}
			}
			q.pop();
		}
		cout << mi << endl;
	}
	return 0;
}