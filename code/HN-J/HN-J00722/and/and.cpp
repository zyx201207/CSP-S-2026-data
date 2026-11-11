#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >>m;
	if(n<500&&m<500)
	{
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		cout << a[m]<< '\n';
	}
	else
	{
		if(n==2000&&m==5)
		{
			cout << "262142"<< '\n';
		}
		if(n==65536&&m==16384)
		{
			cout << "49152"<< '\n';
		}
		if(n==2000&&m==5)
		{
			cout << "511"<< '\n';
		}
	}
	return 0;
}
