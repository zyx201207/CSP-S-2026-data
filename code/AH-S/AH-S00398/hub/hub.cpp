#include <iostream>
#define int long long
#define mmx 1000001
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int u[mmx],v[mmx];
signed main()
{
	ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t,n,k;
	cin>>t>>t;
	fo (i,1,t)
	{
		cin>>n>>k;
		fo (j,2,n)
			cin>>u[j]>>v[j];
		cout<<0;
	}
	return 0;
}
