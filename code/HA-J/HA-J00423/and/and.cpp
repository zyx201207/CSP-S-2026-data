#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	int mx;
	for(int i =1;i<=n;i++)
	{
		cin >> a[i];
		mx = max(mx,a[i]);
		if(i ==1) ans= a[1];
		ans = ans&a[i];
	}
	if(m == 1) cout<<mx;
	if(m == n) cout<<ans;
	return 0;
}
