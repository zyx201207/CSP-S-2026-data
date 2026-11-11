#include<bits/stdc++.h>
using namespace std;
int tong[600000];
int v[1008600];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[600000];
    for(int i=1;i<=n;i++)
    {
	    cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
	    memset(v,0,sizeof(v));
	    for(int j=i;j<=n;j++)
	    {
			for(int k=i;k<j;k++)
			{
				if(a[k]==a[j])
				{
					memset(v,0,sizeof(v));
					break;
				}
			}
			v[j]=a[j];
		}
		for(auto q:v)
		{
			tong[q]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
}