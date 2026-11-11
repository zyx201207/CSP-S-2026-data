#include<bits/stdc++.h>
using namespace std;
const int N = 3e6+10;
long long n,m,a[N],xo = -999999;
bool cmp(long long a,long long b)
{
	return a >= b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	long long s = -9999999;
	sort(a,a + n,cmp);
	for(int i = 0;i < n;i++)
	{
		if(i + m > n)
		{
			break;
		}
		for(int j = i;j <= i + m - 1;j++)
		{
			s = a[j] & a[j + 1];
		} 
		if(s >= xo)
		{
			xo = s;
			s = 0;
		}
	}
	cout << xo;
	
}
