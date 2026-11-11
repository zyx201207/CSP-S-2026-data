#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+7,N=5e2+7;
int c,n,m,d,q,x,y,w[M],k[N];
int minn=INT_MAX;
struct st{
	int w,t;
};
vector<st>a[N]; 
vector<int>sta[M];
bool vis[M];
void dfs(int x1,int time,int last){
	if(x1==y){
		minn=min(minn,time);
		return ;
	}
	for(int i=0;i<sta[x1].size();i++){
		int line=sta[x1][i];
		for(int j=0;j<a[line].size();j++){
			if(vis[a[line][j].w]==0){
				vis[a[line][j].w]=1;
				dfs(a[line][j].w,time+a[line][j].t*2,x1);
				vis[a[line][j].w]=0;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int w1,t1;
			cin>>w1>>t1;
			a[i].push_back({w1,t1});
			sta[w1].push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		minn=INT_MAX;
		dfs(x,w[x]+w[y],x);
		cout<<minn<<'\n';
	}
	return 0; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
