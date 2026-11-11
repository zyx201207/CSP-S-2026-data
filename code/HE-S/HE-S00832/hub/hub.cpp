#include<bits/stdc++.h>
using namespace std;
int vec[60][60];
void dfs(int fa,int r){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
	int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)vec[i][j]=0x3f3f3f3f;
				else vec[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			int u,v;
			vec[u][v]=vec[v][u]=1;
		}
		for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			max(ans,vec[i][j]);
		}
	}
	cout<<ans<<endl;
	}
	return 0;
} 
