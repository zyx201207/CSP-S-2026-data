#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i ++)
	{
		b[i] = a[i];
	}
	int x = b[1] & b[2];
	for(int i = 3;i <= m;i ++)
	{
		x = x & b[i];
	}
	cout << x;
} 

