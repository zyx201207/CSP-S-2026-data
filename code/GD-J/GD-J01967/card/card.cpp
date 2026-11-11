#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[300005],x[500005],cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int t[m+1],k[m+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(t,0,sizeof(t));
		memset(k,0,sizeof(k));
		cnt=0;
		for(int j=i;j<=n;j++)
		{	
			if(t[a[j]])
			{
				while(x[cnt]!=a[j])
				{
					t[x[cnt]]--;
					cnt--;
				}
			}
			t[a[j]]++;
			x[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++)
		{
			if(!k[x[j]])
			{
				d[x[j]]++;
			}
			k[x[j]]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<' '; 
	}
}
