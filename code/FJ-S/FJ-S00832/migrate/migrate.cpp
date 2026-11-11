#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,m,a[2000005],zd[2000005],fa[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				fa[j]=0;
				zd[j]=2E9;
			}
			zd[i]=0;
			fa[i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=1;j-k>=i and a[j]-a[j-k]<=m;k++){
					if(j-k>=i){
						if(zd[j]==zd[j-k]+1){
							fa[j]+=fa[j-k];
						}else if(zd[j]>zd[j-k]+1){
							
						zd[j]=min(zd[j-k]+1,zd[j]);
						fa[j]=fa[j-k];
						}
					}else{
						break;
					}
						
				}
			}
			for(int j=i+1;j<=n;j++){
			//	cout<<zd[j]<<" "<<fa[j]<<" "<<j<<endl;
				if(fa[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
