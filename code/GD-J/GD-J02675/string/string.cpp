#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],ans,i=1,m;
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(i<n)
	{
		m=min(a[i],a[n]);
		if(c[i]!=c[n])
		{
			ans+=m;
		}
		a[i]-=m;
		a[n]-=m;
		if(a[i]==0)
		{
			i++;
		}
		if(a[n]==0)
		{
			n--;
		}
	}
	cout<<ans;
	return 0;
}
