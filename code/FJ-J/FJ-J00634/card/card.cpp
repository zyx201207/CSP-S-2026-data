#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],t[500005][2],ans[500005][2],cnt[5000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[i][0]=1;
		ans[i][1]=a[i];
		if(t[a[i]][0]==1)
		{
			ans[t[a[i]][1]][0]-=1;
			ans[i][0]+=1;
			t[a[i]][0]--;
		}
		if(t[a[i]][0]==0)
		{
			t[a[i]][1]=i;
		}
		t[a[i]][0]++;
	}
	for(long long i=1;i<=n;i++)
	{
		ans[i][0]+=ans[i-1][0];
		cnt[ans[i][1]]+=ans[i][0];
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';	
	}
	return 0;
}