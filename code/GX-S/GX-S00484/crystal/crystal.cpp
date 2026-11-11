#include <bits/stdc++.h>
using namespace std;
int n, maxn=0;
unsigned long long m, b[5000005];
long long a[5000005];
int lj(int l)
{
	int ans=1, c=1;
	unsigned long long j=m;
	for(int i=l;i<=n-1;i++)
	{
		unsigned long long tmp = b[i];
		tmp *= c;
		if(j>=tmp)
		{
			ans++;
			j = j-tmp;
			cout << "b=" << b[i] << " " << "tmp=" << tmp << " " << "ans=" << ans << endl;
		}
		else 
			break;
		c += 1;
	}
	return ans; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		cout << "i=" << i << " " << endl;
		int o = lj(i);
		maxn = max(o,maxn);
	}
	cout << maxn; 
	return 0;
}
