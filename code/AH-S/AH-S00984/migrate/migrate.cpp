#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,t,a[2000010],c,d[5010][5010],vis[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    if(c==11||c==12){
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
			if(2ll*(a[2]-a[1])>m){
				cout<<"0"<<endl;
				continue;
			}else{
				sum=(a[2]-a[1]+m-1)/(a[2]-a[1]);
				cout<<max(0ll,(n-(sum+1))*(sum-1)-(sum-1)*(sum-2)/2)<<endl;
			}
		}else{
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					d[i][j]=1;
					d[j][i]=1;
					vis[i][j]=1;
					vis[j][i]=1;
				}
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				if(d[i][j]!=0){
					for(int k=j+1;k<=n;k++){
						if(d[j][k]!=0){
							if(d[i][k]==0){
								d[i][k]=d[i][j]+d[j][k];
								d[k][i]=d[i][j]+d[j][k];
								vis[i][k]=1;
								vis[k][i]=1;
							}else{
								if(d[i][k]==d[i][j]+d[j][k]){
									vis[i][k]++;
									vis[k][i]++;
								}else if(d[i][k]>d[i][j]+d[j][k]){
									vis[i][k]=1;
							    	vis[k][i]=1;
								    d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
							    	d[k][i]=min(d[i][k],d[i][j]+d[j][k]);
								}
							}
						}
					}	
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(vis[i][j]==2){
					ans++;
				}
				//cout<<vis[i][j]<<" ";
			}
			//cout<<endl;
		}	
		cout<<ans<<endl;
	}
 	}
	return 0;
}

