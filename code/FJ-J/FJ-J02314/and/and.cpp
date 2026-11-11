#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=1e10;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=min(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
