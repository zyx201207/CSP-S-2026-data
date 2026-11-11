#include <bits/stdc++.h>
using namespace std;
int a[100000005],b;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
		cin >> a[i];
	b=m-3;
	if(b>m-3)
		a[0]=a[0]+b;
		a[1]=a[1]+m-3;
	if(b<m-3)
		a[0]=a[0]+m-3;
		a[1]=a[1]+b;
	if (a[0]==a[1]||a[1]==a[2])
	    ans+=3;
	else
		ans+=4;
	cout << ans;
	return 0;
}
