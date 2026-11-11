#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=2e4+5,N=505;
int w[M],k[N],a[N][M],t[N][M];
vector<int> xl[M];
int xr,yr;
long long minn=2e18;
bool vis[M];
void dfs(int now_xl,int zd,long long sum){
	if(zd==yr){
		minn=min(minn,sum+t[now_xl][zd]+w[yr]);
		return ;
	}
	
	for(auto i:xl[zd]){
		for(int j=1;j<=k[i];j++){
			if(vis[a[i][j]])continue;
			vis[a[i][j]]=1;
			if(i==now_xl){
				dfs(i,a[i][j],sum+t[i][j]);
			}
			else {
				dfs(i,a[i][j],sum+t[now_xl][j]+t[i][j]);
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			xl[a[i][j]].push_back(i);
		}
	}
	
	while(q--){
		minn=2e18;
		cin>>xr>>yr;
		
		for(auto i:xl[xr]){
			memset(vis,0,sizeof vis);	
			dfs(i,xr,w[xr]);
		}
		cout<<minn<<"\n";
	}
	return 0;
}
