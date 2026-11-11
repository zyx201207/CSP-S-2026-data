#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(m>1)
	{
		if(m%2==0)
		{
			a[n]=a[n]&&a[m/2];
			m--;
		}
		else 
		{
			a[n]=a[n]&&a[n-m/2-1];
			m--;
		}
	}
	cout<<a[n];
	return 0;
}
