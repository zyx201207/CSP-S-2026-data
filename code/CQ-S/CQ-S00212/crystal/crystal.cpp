#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x=1,ans=1;
int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m; for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<=m;i++){
		sort(a,a+n);
		for (int j=1;j<n;j++)
			if(a[j]==a[j-1])
			{
				x++;
				if(x>ans) ans=x;
			}
			else x=1;
		a[0]++;
	}
	cout << ans;
	return 0;
}
