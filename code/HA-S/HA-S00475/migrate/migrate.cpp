#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],f[5005][5005],tot[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=1e17;
				tot[i][j]=0;
				if(i==j){
					f[i][j]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i;j>=max((int)(1),i-d);j--){
				if(a[i]-a[j]>d){
					break;
				}
				f[i][j]=1;
				f[j][i]=1;
			}
			for(int j=i;j<=min(n,i+d);j++){
				if(a[j]-a[i]>d){
					break;
				}
				f[i][j]=1;
				f[j][i]=1;
			}
		} 
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
						tot[i][j]=max((int)(1),tot[i][k]);
					}
					else if(f[i][j]==f[i][k]+f[k][j]){
						tot[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(tot[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
		
	return 0;
}
