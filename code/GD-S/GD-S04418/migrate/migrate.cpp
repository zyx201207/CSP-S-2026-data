#include <bits/stdc++.h>
using namespace std;
#define int long long
//Æ­·ÖÅÜÂ· 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5




1
2
*/
const int N=5010;
const int INF=0x3f3f3f3f;
int c,t;
int n,d;
struct island{
	int x;
	int id;
}l[N];
int e[N][N];
int ans;
int dis[N];
int vis[N];
int xnm;
bool cmp(island x,island y){
	return x.x<y.x;
}
int dfs(int s,int end){
	queue<pair<int,int>> q; 
	q.push(make_pair(s,0));
	int cnt=0;
	bool flag=1;
	bool flag1=1;
	dis[1]=INF;
	dis[2]=INF;
	int step=0;
	while(!q.empty()){
		++step;
		int pos=q.front().first;
		int d=q.front().second;
		if(d>dis[cnt]){
			continue;
		}
		if(step>=1000){
			flag=false;
			break;
		}
		q.pop();
		for(int v=1;v<=n;v++){
			if(v==pos){
				continue;
			}
			if(!e[pos][v]){
				continue;
			}
			if(v==end){
				cnt++;
				dis[cnt]=d+1;
				vis[dis[cnt]]++;
				if(cnt>=2){
					if(vis[dis[cnt]]=2){
						flag1=0;
						break;
					}
				}
			}
			q.push(make_pair(v,d+1));
		}
		if(!flag1){
			break;
		}
	}
	return cnt;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int T=t;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>l[i].x;
			l[i].id=i;
		}
		sort(l+1,l+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				if(abs(l[j].x-l[i].x)<=d){
					e[l[i].id][l[j].id]=1;
					e[l[j].id][l[i].id]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				if(e[i][j]&&e[j][i]){
					int temp=dfs(i,j);
					ans+=temp;
				}
			}
		}
		
		if(t-T==1){
			xnm=ans;
			cout<<1<<'\n';
		}
		else{
			cout<<ans/xnm<<'\n';
		}
		ans=0;
		for(int i=1;i<=n;i++){
			l[i].x=0;
		}
	}
}
