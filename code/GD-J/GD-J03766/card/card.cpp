#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],num[500005];
int hy(int c)
{
	for(int i=1;i<=c-1;i++)
	{
		if(b[i]==a[c])
		    return i;
	}
	return 0;
}
bool sc(int d)
{
	if(d==0)
	    return 0;
	for(int i=d;i<=n;i++)
		b[i]=0;
	return 0;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","W",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	for(int i=1;i<=n;i++)
		    b[i]=0;
		for(int j=i;j<=n;j++)
    	{
    		sc(hy(j));
    		b[j]=a[j];
		}
		for(int i=1;i<=n;i++)
		    num[b[i]]++;
	}
	for(int i=1;i<=m;i++)
	    cout<<num[i]<<" ";
    return 0;
}
