#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1000005];
int f[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) f[i][j]=0;
				f[i][j]=abs(a[i]-a[j]);
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int ans=0;
		for(int l=1;l<=n-1;l++){
			for(int r=l+1;r<=n;r++){
				int cnt=0;
				for(int i=l;i<=r;i++){
					if(f[l][i]+f[i][r]==f[l][r]) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}





	return 0;
}
