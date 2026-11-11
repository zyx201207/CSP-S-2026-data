#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[100005],b[100005];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	for(int u=1;u<=m;u++)
	{
		int j=0,s=0;
		for(int i=u-1;i<n;i++)
		{
			b[j]=a[i];
			for(int v=0;v<i;v++)
			{
				if(b[v]==b[j])
				{
					for(int p=v;p<j;p++)b[p]=0;
				}
			}
		}
		for(int i=u-1;i<n;i++)
		{
			if(b[i]==u)s++;
			b[i]=0;
		}
		cout<<s<<' ';
	}


    return 0;
}

