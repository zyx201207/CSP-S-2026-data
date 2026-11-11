#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 0;i < n;i++)
	{
		b[cnt++] = a[i] & 1;
		a[i] >>= 1;
		for(int j = cnt;j >= 0;j--)
		{
			cout << b[i] << ' ';
		}
	}
	return 0;
}
