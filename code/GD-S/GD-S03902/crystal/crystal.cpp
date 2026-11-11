#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt=-1;
int a[500005],s[500005];
long long b[500005];
bool cmp(int a,int b)
{
	return s[a] < s[b];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	s[1]=a[1];
	b[1] =a[1];
	for (int i = 1;i <= n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 2;i <= n;i++)
	{
		b[i] = b[i-1]+a[i];
		s[i] = b[i] - a[i]; 
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i <= n;i++)
	{
		m-=s[i];
		cnt++;
		if (m <= 0)
		{
			break;
		}
		
	}
	cout << cnt;
}
