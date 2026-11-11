#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	string c[200005];
	long long ans=0;
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i =1;i<=(n+1)/2;i++)
	{
		if(c[i]!=c[n-i])
		{
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
