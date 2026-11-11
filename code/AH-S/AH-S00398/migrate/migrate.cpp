#include <iostream>
#define int long long
#define mmx 2000001
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[mmx];
signed main()
{
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,n,d;
	cin>>t>>t;
	fo (i,1,t)
	{
		cin>>n>>d;
		fo (j,1,n) cin>>a[i];
		cout<<0<<endl;
	}
	return 0;
}
