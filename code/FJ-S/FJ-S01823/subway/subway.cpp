#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+3;
int c,n,m,d,qq,x,y;
int w[N],k[N];
map<int,map<int,int>>a,t,st;
int dis[N],s[N],qz[N];
void solveB(){
	dis[y]=qz[y];
	return;
}
void solve(){
	queue<int>q;
	q.push(x);
	for(int i=1;i<=m;i++)dis[i]=1e18,s[i]=0;
	dis[x]=w[x];
	while(q.size()){
		int u=q.front();
		q.pop();
		if(s[u])continue;
		s[u]=1;
		for(int i=1;i<=n;i++){
			if(st[u][i]){
				for(int j=1;j<=k[i];j++){
					if(dis[u]+t[i][u]+t[i][a[i][j]]<dis[a[i][j]]){
						dis[a[i][j]]=dis[u]+t[i][a[i][j]]+t[i][u];
						q.push(a[i][j]);
					}
				}
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			st[a[i][j]][i]=1;
		}
	}
	for(int i=1;i<=m;i++){
		qz[i]=qz[i-1]+t[0][i]+t[1][i];
	}
	while(qq--){
		cin>>x>>y;
		if(c>=7&&c<=11)solveB();
		else solve();
		cout<<dis[y]+w[y]<<endl;
	}
	return 0;
}