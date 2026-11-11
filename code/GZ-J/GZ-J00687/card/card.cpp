//贵阳中天中学裴天元GZ-J00687
#include<bits/stdc++.h>
using namespace std;
struct banana
{
	int cnt=0;bool in=0;
};
int n,m,a[5005];bool an[5005][3005];
bool b[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];b[a[i]]++;
	}
	for (int k=0;k<n;k++)
	{
		banana c[5005]={};
		int d[5005]={}; 
		int cnt=0;
		for (int i=1+k;i<=n;i++)
		{
			d[++cnt]=a[i];
			if (c[a[i]].cnt!=0 and c[a[i]].in==0)
			{
				for (int j=cnt;j>=c[a[i]].cnt;j--)
				{
					c[d[j]].in=1;
				}
			}
			c[a[i]].cnt=cnt;c[a[i]].in=0;
		}
		
		for (int i=1;i<=5000;i++)
		{
			if (c[i].cnt!=0 and c[i].in==0)
			{
				an[k+1][i]=1;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)cnt+=an[j][i];
		cout<<cnt<<' ';
	}
	return 0;
}
