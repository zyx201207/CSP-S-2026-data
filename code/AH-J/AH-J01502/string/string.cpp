#include<bits/stdc++.h>
using namespace std;
char a[1000005],c[1000005],d[1000005];
long long i,n,b[1000005],j,k=0,x=0,z=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
		cin>>b[i]>>a[i];
    for(i=1;i<=n;i++)
    {
		for(j=1;j<=b[i];j++)
		{
			k++;
			c[k]=a[i];
		}
	}
	for(i=k;i>=1;i--)
	{
		x++;
		d[x]=c[i];

	}
	for(i=1;i<=k;i++)
	{
		if(d[i]!=c[i])z++;
	}
	cout<<z/2;
    return 0;
}
