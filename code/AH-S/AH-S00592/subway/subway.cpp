#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e3+10;
const int M=5e5+10;

int c,n,m,d,q;
int w[M];
int k[N];

unordered_map<int,int>sub[N];
int g[N][N];

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<N;i++)g[i][i]=0;
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			
			sub[i][a]=t;
		}
	}
	
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			for(auto it:sub[i]){
				if(sub[j][it.first]==0){
					continue;
				}
				g[i][j]=g[j][i]=min(g[i][j],it.second+sub[j][it.first]);
			}
			//cout<<i<<'-'<<j<<'-'<<g[i][j]<<'\n';
		}
	}
	
	for(int h=1;h<=n;h++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(g[i][j]>g[i][h]+g[h][j]){
					g[i][j]=g[i][h]+g[h][j];
				}
			}
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<'+'<<j<<'+'<<g[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
		//cout<<'\n';
		//cout<<w[x]+w[y]<<'\n';
		
		int ans=2e9+10;;
		
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(sub[j][x]&&sub[l][y]){
					//cout<<j<<' '<<l<<"="<<sub[j][x]<<' '<<sub[l][y]<<' '<<g[j][l]<<'\n';
					ans=min(ans,sub[j][x]+sub[l][y]+g[j][l]);
				}
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	
	/*
	sub[1]=1;
	sub[3]=4;
	cout<<sub[1]<<' ';
	cout<<sub[4]<<'\n';
	
	for(auto it:sub){
		cout<<it.first<<' '<<it.second<<'\n';
	}
	*/
	
	return 0;
}
