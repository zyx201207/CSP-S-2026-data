//card

#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300001],e[3000001],a[500001],b[3000001],k1[300001],k2[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!b[a[i]]) b[a[i]]=i;
		else
		{
			k1[b[a[i]]]++;
			k1[i]++; 
			e[b[a[i]]]=i;
			b[a[i]]=i;
		}
	}
	int num=0,vis=0,t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(k1[j])
			{
				if(!t) t=a[j];
				if(a[j]==t)
				{
					if(!vis) vis=1;
					else
					{
						vis=0;
						t=0;
					}
				}
			}
			if(vis) continue;
			ans[a[j]]++;
		}
		if(k1[i]) k1[e[i]]--;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}

