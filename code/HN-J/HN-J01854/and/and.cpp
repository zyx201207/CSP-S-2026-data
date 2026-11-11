#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,v,j;
	long long max=0;
	long long a[n];
	
	cin>>n,m;
	for(i=1;i<=n;i++)
	{
		cin>>a[n];
	}
	if(m==2)
	{
		v=(n+1)*n/2;
		long long b[v];
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=i;j++)
			{
				b[i]=a[j]&a[j+1];
			}
		}
	}
	sort(b,b+v);
	cout<<b[v];
	return 0
)
