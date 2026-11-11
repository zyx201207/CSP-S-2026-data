#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long c,t,n,d,k,x,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		k=a[2]-a[1];
		if(k>=d){
			cout<<0<<'\n';
			continue;
		}
		x=d/k;
		cout<<max(0ll,n-x*2+1)<<'\n';
	}
	return 0;
}
