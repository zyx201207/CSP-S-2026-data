//GZ-S00386 吴显鑫 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000010];
long long ans;
int main() {
	freopen("migrate.in","r",stdin);//注意等一下修改 
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		ans+=(a[n]/d)*(d*(d-1)/2);
		ans+=((a[n]%d)*(a[n]%d-1)/2);
		cout<<ans<<endl;
	}
	return 0;	
}
