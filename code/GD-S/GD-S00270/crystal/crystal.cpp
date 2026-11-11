#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[500001],m,l,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int z=1;z<=n;z++)
	  cin>>a[z];
	sort(a+1,a+1+n);
	for(int z=1;z<=n;z++)
	{
		m-=(a[z]-a[z-1])*(z-l-1);
		while(m<0)
		{
			l++;
			m+=a[z]-a[l];
		}
		ans=max(ans,z-l);
	}
	cout<<ans;
	return 0;
}
