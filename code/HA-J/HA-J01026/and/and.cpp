#include <bits/stdc++.h> 
using namespace std;
int main()
{
	fropen("and.in","r",stdin);
	fropen("and.out","w",stdout);
	int n,m,a[100005],b=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b=a[1];
	if(m==1) 
	{
		cout<<a[n];
		return 0;
	}
	if (m==n)
	{
		fot (int i=1;i<=n;i++)
		{
			b=a[i]&&b;
		}
		cout<<b;
		return 0;
	}
	cout<<a[1];
	return 0;
}

