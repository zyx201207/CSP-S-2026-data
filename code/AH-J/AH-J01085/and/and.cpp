#include<bits/stdc++.h>
using namespace std;
long long b[200005],a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,i,m,j,t=0,t1=0,t2=0,ma;
	cin>>n>>m;
	int n1=n;
	while(n1!=0)
	{
		if(n1%2==1)
		{
			t=1;
			break;
		}
		n1/=2;
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i-1)
		{
			t1=1;
		}
		int tt=a[i]+1;
		while(tt!=0)
		{
			if(tt%2==1)
			{
				t2=1;
				break;
			}
			tt/=2;
		}
	}
	if((t==0&&t1==0)||t2==0)
	{
		sort(a+1,a+n+1);
		ma=a[n];
		for(i=n-1;i>=n-m+1;i--)
		{
			ma=ma&a[i];
		}
		cout<<ma;
		return 0;
	}
	b[1]=a[1];
	for(i=2;i<=n;i++)
	{
		for(j=i;j>=2;j--)
		{
			b[j]=max(b[j],(b[j-1]&a[i]));
		}
		b[1]=max(b[1],a[i]);
	}
	cout<<b[m];
}
