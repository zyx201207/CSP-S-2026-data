#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],t[20][N],a[N],ans,vis[N];
vector<int>G[N];
void dfs(int x,int xi,int end,int sum){
	if(x==end){
		ans=sum;
		return ;
	}
	for(int i:G[x]){
		if(!vis[i]){
			vis[i]=1;
			if(xi==a[i])dfs(i,a[i],end,sum);
			else if(sum==0)dfs(i,a[i],end,sum+t[a[i]][i]);
			else dfs(i,a[i],end,sum+t[xi][i]+t[a[i]][i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	bool flag=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int last;
		for(int j=1;j<=x;j++){
			int x,y;
			cin>>x>>y;
			a[x]=i,t[i][x]=y;
			if(j!=1){
				G[x].push_back(last);
				G[last].push_back(x);
			}
			last=x;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j:G[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dfs(u,a[u],v,0);
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
