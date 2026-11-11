#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	//B
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-a[1])<=d&&abs(a[n]-a[1])<=d)
		{
			cout<<1;
			return 0;
		}
	}
}
