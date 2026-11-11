#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],tt[300005],t[300005],sum,ii,b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		t[a[i]]++;
		if(t[a[i]]==1)
		{
			ii++;
			tt[ii]=-1;
			sum++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		t[i]=0;
	}
	sort(tt+1,tt+sum+1);
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			t[a[j]]++;
			if(t[a[j]]>1)
			{
				for(int jj=j;jj>=i;jj--)
				{
					t[jj]=0;
				}
				t[a[j]]++;
			}
			else
			{
				if(tt[a[j]]==-1)
				{
					tt[a[j]]=0;
				}
				tt[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			t[j]=0;
		}
	}
	for(int i=1;i<=sum;i++)
	{
		cout<<tt[i]<<" ";
	}
	return 0;
}
