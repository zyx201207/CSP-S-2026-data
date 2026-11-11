#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long c,t,n,d,del,x[N];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	del=x[2]-x[1];
	if(d<del*2)
	{
		cout<<"0\n";
		return;
	}
	long long limit=d/del;
	limit*=2,limit--;
	if(limit>n) cout<<"0\n";
	else cout<<n-limit<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
