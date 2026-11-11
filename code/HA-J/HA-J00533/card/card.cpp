#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],k=1,flag=0,c,c1[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(b[j]==a[i+i-1])
			{
				flag=1;
				c=j;
				break;
			}
		}
		if(flag==0)
		{
			b[k]=a[i+i-1];
			k++;
		}
		else if(flag==1)
		{
			k=c;
			b[k]=a[i+i-1];
			k++;
			
		}
		for(int j=1;j<=k;j++)
		{
			if(b[j]!=0)
			{
				c1[b[j]]++;
			}
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c1[i]<<" ";
	}
	return 0;
}
