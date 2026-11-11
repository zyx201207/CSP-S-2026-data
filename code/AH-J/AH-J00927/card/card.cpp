#include<bits/stdc++.h>
using namespace std;
int a[600000],pos[600000],cnt[600000],b[600000],ans[600000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=0,d=n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	while(d!=0)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			cnt[a[i]]=0;
			pos[a[i]]=0;
		}
		for(int i=n-d+1;i<=n;i++)
		{
			a[i]=a[i-d];
			cnt[a[i]]++;
			if(cnt[a[i]]==1)
			{
				pos[a[i]]=i;
			}
			if(cnt[a[i]]==2)
			{
				for(int j=1;j<pos[a[i]];j++)
				{
					b[++t]=a[j];
				}
				t++;
				b[t]=a[i];
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=t;j++)
			{
				if(b[j]==i)
				{
					ans[i]++;
				}
			}
		}
		d--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
