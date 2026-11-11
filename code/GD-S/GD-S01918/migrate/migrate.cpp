#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[10005],a[10005][10005],aa[10005][10005];
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){a[i][j]=0x3f3f3f; aa[i][j]=1; }
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=k){
					a[i][j]=1;
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				for(int j=k+1;j<=n;j++){
					if(a[i][j]==a[i][k]+a[k][j]) {
						aa[i][j]++;
					}
					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
						aa[i][j]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(aa[i][j]==2&&a[i][j]!=1) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
