#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+2;
int x[N],cnt[5008][5002];
signed main(){
	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt[i][j]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)cnt[i][j]=1;
				else{
					for(int k=i+1;k<j;k++){
						if(x[k]-x[i]<=d&&x[j]-x[k]<=d)cnt[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}