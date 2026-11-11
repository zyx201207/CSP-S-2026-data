#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> table(500005);
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	vector<int>a(n+1);
	vector<int>ans(m+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int> cnt(m+1);
		vector<int> pos(m+1);
		int t;
		for(int j=i;j<=n;j++)
		{
			if(j==1)t=j;
			if(cnt[a[j]]!=0)
			{
				for(int k=pos[a[j]];k<=n;k++)
				{
					cnt[table[k]]--;
					table[k]=0;
					t--;
				}
			}
			pos[a[j]]=t;
			cnt[a[j]]++;
			table[t]=a[j];
		}
		for(int j=1;j<=m;j++)
		{
			if(a[j]!=0)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}