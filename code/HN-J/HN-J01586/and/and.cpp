#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],b1=0,bs;
int main( )
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int maxn=-1,t;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>maxn)
			{
				maxn=a[j];
				t=j;
			}
		}
		a[t]=-1;
		b1++;
		b[b1]=maxn;
	}
	if(m==1)
	{
		cout<<b[1];
		return 0;
	}
	for(int i=2;i<=b1;i++)b[1]=b[1]&b[i];
	cout<<b[1];
	return 0;
}

