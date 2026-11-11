#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int c,t,ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,a[maxn];
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if((a[i]-a[j])%d!=0&&a[i]-a[j]>d){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
