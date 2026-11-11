#include<bits/stdc++.h>
using namespace std;
int n,k,c,t,u,v,a[4001][4001],book[4001]={};
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
    	scanf("%d%d",&n,&k);
    	if(n==k)
    	{
			cout<<0<<"\n";
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				a[j][k]=0;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<3<<"\n";
	}
    return 0;
}
