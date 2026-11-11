#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(i == 1)
			cnt = a[i];
		else
			cnt &= a[i];
	}
	if(m == n)
	{
		cout << cnt;
		return 0;
	}
	sort(a + 1,a + 1 + n,cmp);
	if(m == 1)
	{
		cout << a[1];
		return 0;
	}
	cnt = a[1] & a[2];
	for(int i = 3;i <= m;i++)
		cnt &= a[i];
	cout << cnt;
	return 0;
}
