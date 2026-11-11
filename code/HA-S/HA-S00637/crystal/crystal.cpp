#include <bits/stdc++.h>
using namespace std;

long long m,a[500005],b[500005],cnt;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int mid=(n+1)/2;
	long long t=a[mid];
	for (int i=1;i<=n;i++)
	{
		b[i]=abs(a[i]-a[mid]);
	}
	sort(b+1,b+n+1);
	int k=1;
	while (k<=n)
	{
		if (m>=b[k])
		{
			m-=b[k];
			cnt++;
		}
		else
		{
			break;
		}
		k++;
	}
	cout << cnt;
	return 0;
} 
