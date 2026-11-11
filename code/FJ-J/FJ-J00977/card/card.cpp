#include<bits/stdc++.h>
using namespace std;
long long int n,m,h=0,num=1,kill=0;
long long int a[500005],b[500005],del[500005];
long long int c[300005];
bool tf[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tf[a[i]]=false;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(tf[a[j]]==true)
			{
				for(int k=del[a[j]];k<=j-1;k++)
				{
					if(b[k]!=0)
					{
						b[k]=0;
						kill++;
					}
					
				}
				num-=kill;
				kill=0;
				b[num]=a[j];
			}
			else
			{
				b[num]=a[j];
				tf[a[j]]=true;
				del[a[j]]=num;
			}
			num++;	
		}
		
		for(int j=1;j<=num;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(b[j]==k)
				{
					b[j]=0;
					c[k]++;
					break;
				}
			}
		}
		kill=0;
		h=0;
		for(int j=1;j<=m;j++)
		{
			tf[j]=false;
			del[j]=0;
		}
		num=1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}

