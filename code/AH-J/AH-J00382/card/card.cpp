#include<bits/stdc++.h>
using namespace std;
int cnt[300005];
int a[500005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int idx1=0,idx2=0,num=0;
	for(int i=n;i>=1;i--)
	{
		if(cnt[a[i]]==1)
		{
			num=a[i];
			idx1=i;
			break;
		}
		cnt[a[i]]++;
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==num) 
		{
			idx2=i;
			break;
		}
	}
	for(int i=idx2;i<=n;i++)
	{
		ans[a[i]]=idx1;
	}
	for(int i=idx1+1;i<=n;i++)
	{
		ans[a[i]]+=i-idx1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
