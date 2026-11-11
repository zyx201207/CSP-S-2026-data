#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	for(int i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
			ans+=min(a[i],a[j]);
		}
		if(a[i]>=a[j])
		{
			a[i]-=a[j];
			--j;
		}
		else
		{
			a[j]-=a[i];
			++i;
		}
	}
	cout<<ans;
	return 0;
} 
/*

*/
