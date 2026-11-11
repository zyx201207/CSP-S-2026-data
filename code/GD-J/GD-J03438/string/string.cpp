#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[10000005],n;
	string c;
	long long ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c;
		ans+=a[i];
	}
	cout << ans/2;
	return 0;
}
