#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000000],ans,vis[1000000],minv[100000];
void dfs(int s,int pos){
	if(s<minv[pos]){
		vis[pos]=1;
		minv[pos]=s;
		for(int i=pos+1;x[i]-x[pos]<=d&&i<=n;i++){
			dfs(s+1,i);
		}
	}else if(s==minv[pos]){
		vis[pos]++;
		for(int i=pos+1;x[i]-x[pos]<=d&&i<=n;i++){
			dfs(s+1,i);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++){
			memset(vis,0,sizeof(vis));
			memset(minv,0x3f,sizeof(minv));
			dfs(1,i);
			for(int j=i+1;j<=n;j++){
				if(vis[j]==2){
					ans++; 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
