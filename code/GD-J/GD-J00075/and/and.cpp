#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}
int a[200005] = {};
int b[200005] = {};

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	long long sum = a[1];
	for(int i = 1;i <= n;i++) b[i] = 1;
	for(int i = 1;i <= m;i++)
	{
		int num[200005] = {};
		int max = 0;
		int d = 0;
		for(int j = 1;j <= n;j++)
		{
			if(j == i || b[j] == 0) continue;
			num[j] = sum & a[j];
			if(b[j] && num[j] > max)
			{
				max = num[j];
				d = j;
			}
		}
		b[d] = 0;
		sum &= a[d];
	}
	cout << sum << endl;
	return 0;
}
