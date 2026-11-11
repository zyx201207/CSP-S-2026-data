#include <bits/stdc++.h>
using namespace std;
int a[500001]={0};
void mix();
int main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	int n,h,y,x=0;
	int z=1,max=0,maxn;
	long long m;
	cin >> n>>m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int j=0;j<n;j++)
	{
	for(int i=0;i<n-j;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			maxn=i;
		}
	}
	a[maxn]=a[n-1-j];
	a[n-1-j]=max;
	max=0;
}
	for(int i=1;i<n;i++)
	{
	while (m>=i&&a[0]<a[i])
	{
		a[0]++;
		m=m-i;
		if(m<0)
		{
			cout<<z;
			return 0;
		}

	}
	if(a[i]==a[0])
	{
		z++;

	}
	}


	cout<<z;
	return 0;
 }
