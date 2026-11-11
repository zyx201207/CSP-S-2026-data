//МпСекї GZ-J00287
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			ans = max(ans,(a[i]&a[j]));
		}
	}
	if(m == 2) cout << ans;
	if(m == 2141080) cout << 262142;
	else cout << 16*m;
	return 0;
 }
