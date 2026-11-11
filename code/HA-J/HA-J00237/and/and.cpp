#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0;
    for (int i=n;i>=n-m+2;i--)
    {
    	int x=a[i],y=a[i-1];
    	sum=x&y;
	}
	cout << sum;
	return 0;
}

