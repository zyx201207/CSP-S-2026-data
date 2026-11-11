#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	cout<<ans;

	return 0;
}
