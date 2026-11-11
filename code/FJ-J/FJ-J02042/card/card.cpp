#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1000005;
int a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		c[i]=0;
		d[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			b[j]=0;
		}
		int lem=1;
		for (int j=i+1;j<=n;j++)
		{
			if (c[a[j]]==0)
			{
				b[lem]=a[j];
				c[b[lem]]++;
				lem++;
			}
			else
			{
				int left;
				for (int l=1;l<=n;l++)
				{
					if (a[j]==b[l])
					{
						left=l;
						break;
					}
				}
				for (int l=left;l<=n;l++)
				{
					c[b[l]]--;
					lem--;
					b[l]=0;
				}
				b[lem]=a[j];
				c[b[lem]]++;
				lem++;
			}
	    }
	    for (int k=1;k<=n;k++)
		{
		    if (b[k]==0) continue;
		    d[b[k]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << d[i] << " ";
	}
	return 0;
} 
