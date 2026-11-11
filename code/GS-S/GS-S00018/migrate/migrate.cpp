#include<bits/stdc++.h>
using namespace std;
int ppppp,n,s,T,a[5009],f[5009][5009] ;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ppppp>>T;
	while(T--){
		cin>>n>>s;
		memset(a,0,sizeof a);
		memset(f,0x3f,sizeof f);
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])>s)continue;
				f[i][j]=f[j][i]=abs(a[i]-a[j]);
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(f[i][j]==f[i][k]+f[k][j]){
						cnt++;
					}
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
