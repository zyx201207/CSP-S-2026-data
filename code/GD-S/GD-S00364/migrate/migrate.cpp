#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int c,t,n,d;
int a[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d){
				int w=a[i+1]+d;
				int pos=upper_bound(a+1,a+n+1,w)-a;
				ans+=pos-i-3;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
