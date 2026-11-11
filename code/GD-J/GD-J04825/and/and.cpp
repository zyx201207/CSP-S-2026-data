#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,ma;
long long a[200005];
string s,s1,s2;
int main ()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >> n >> m ;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	sort (a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		s=' ';
		while (a[i]!=0)
		{
			s=char(a[i]%2+'0')+s;
			a[i]/=2;
		}
		sum=s1&s;
		s1=s;
		
	}
	return 0;
}
