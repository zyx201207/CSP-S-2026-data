#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100009];
	cin>>n>>m;
	int max;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	max=(a[n]&a[n-1]);
	m-=2;
	while(m>0)
	{
		int c=n-1;
		c--;
		max=(max&a[c]);
		m--;
	}
	cout<<max;
	return 0;
}
