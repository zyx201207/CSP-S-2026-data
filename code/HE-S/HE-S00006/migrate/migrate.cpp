#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll ans;
ll a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		a[1000005]={0};
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		ans=n-d-1;
		if(ans<0) ans=0;
		cout<<ans<<endl;
	}
	return 0;
}
