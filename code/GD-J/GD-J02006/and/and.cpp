#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen ("and.ans","w",stdout);
	int n,m,a[30005],maxNumber;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n+1);
	for(int i=n;i>m;i--)
	{
		maxNumber = a[i] & a[i-1];
	}
	cout << maxNumber;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
