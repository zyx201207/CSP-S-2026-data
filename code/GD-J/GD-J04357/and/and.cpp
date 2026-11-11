#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,ans=0;
int a[10005],s[10005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m== 1)
	{
		sort(a + 1,a + n + 1);
		cout << a[n];
	}
    if (m == 2)
    {
    	for (int i = 1;i <= n;i++)
    	{
    		for(int j = i+1;j <= n;j++)
    		{
    			s[i] = a[i] and a[j];
    			ans = max(ans,s[i]);
			}
		}
	}
	cout << ans;
	return 0;
}
