#include <bits/stdc++.h>

using namespace std;

#define int long long
#define SIZE 200005 
int n;
int a[SIZE];
char c[SIZE];
signed main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n ;
	
	for (int i=1;i<=n;++i)
		cin >> a[i] >> c[i] ;
	
	int i=1,j=n,ans=0;
	while (i<j)
	{
		if (a[i]<=a[j])
		{
			a[j]-=a[i];
			if (c[i]==c[j])
			{
				i++;
			} else {
				ans+=a[i];
				i++;
			}
		} else {
			a[i]-=a[j];
			if (c[i]==c[j])
			{
				j--;
			} else {
				ans+=a[j];
				j--;
			}
		}
	}
	
	cout << ans ;
	return 0;
}
