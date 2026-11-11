#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d,k,f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	f=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=i) f=0;
	}
	if(f==1)
	{
		long long p=0,q=1;
		while(1)
		{
			p+=q;
			if(p>m) break;
			q++;
		}
		cout << q;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=-1;
	for(int i=n;i>=1;i--)
	{
		k=0;
		d=0;
		for(int j=i;j>=1;j--)
		{
			d+=a[i]-a[j];
			if(d>m) break;
			k++;
		}
		ans = max(ans,k);
	}
	cout << ans;
	return 0;	
} 
