#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005],wdl[500005];
bool visb[500005];
void mt(int begin,int end)
{
	for(int i=begin;i<=end;i++)
	{
		visb[i]=false;
		wdl[i]=0;
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[i]);
	}
	int ln=n;
	while(ln--)
	{
		for(int i=n-ln;i<=n;i++)
		{
			wdl[i]=a[i];
			for(int j=n-ln;j<=i;j++)
			{
				if(wdl[j]==wdl[i])
				{
					for(int x=j;x<=i;x++)
					{
						wdl[x]=0;
					}
				}
			}
		}
		for(int i=n-ln;i<=n;i++)
		{
			if(wdl[i]!=0&&visb[wdl[i]]!=true)
			{
				b[wdl[i]]++;
				visb[wdl[i]]=true;
			}
		}
		mt(0,n);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
