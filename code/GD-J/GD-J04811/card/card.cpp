#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],bj[500005],cnt[500005],ans[500005],q[300005],k=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(bj,0,sizeof bj);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[a[i]]==0)
		{
			q[k++]=a[i];
			bj[a[i]]=i;
			cnt[a[i]]=1;
		}
		else
		{
			for(int i=bj[a[i]];i<=k;i++)
			{
				cnt[q[i]]=0;
				bj[q[i]]=0;
				q[i]=0;
			}
			for(int i=1;i<=k;i++)
			{
				int b=q[i-1];
				q[i]=b;
			}
			k-=bj[a[i]];
			q[1]=a[i];
			bj[a[i]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(cnt[a[i]]!=0)
			{
				ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
