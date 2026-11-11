#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int M=1e5+5;

int c,n,m,d,q,k,x[M],y[M];
int w[M],t[M];
int edge[M];
vector<int> g(M);
int ans=0;
bool vis[M];
int sum=0;

//最短路 
//性质A  

//int dfs(int x,int y){
//	if(vis[y]==1) return ans;
//	vis[y]=1;
//	dfs(edge[x+1],y);		
//}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>edge[i]>>t[i];
		}
	}
	
	for(int i=1;i<=q;i++) {
		cin>>x[i]>>y[i];
//		dfs(x,y);
//		for(int j=x;j<=y;j++){
//			sum+=w[j];
//		}
//		ans=(y-x)*t[i]+sum<<"\n";
		cout<<(y-x)*t[i];
	}
	return 0;
} 
