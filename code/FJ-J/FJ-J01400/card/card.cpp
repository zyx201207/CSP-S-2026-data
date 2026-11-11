#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],b[100005],c[100005],t=1;
int main()
{
    //freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==1)
		{
			c[i]=i;
		}
		else if(c[i]==2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]==i)
				{
				    b[t]=j;
					t++;	
				}
			}
			c[i]=b[2]-b[1];
		}
	}
	return 0;
}
