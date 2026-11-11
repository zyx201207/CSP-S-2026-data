#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int flag[N];
int b[N];
int ans[N];
int cnt[N];
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
	for(int i=n;i>=1;i--)
	{
		b[i]=flag[a[i]];
		flag[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++)cnt[i]=0;
		int t=i;
		while(t<=n)
		{
			cnt[a[t]]=1;
			if(b[t]!=0)t=b[t];
			else t++;
		}
		for(int j=1;j<=m;j++)ans[j]+=cnt[j];
		t=i;
		while(t<=n)
		{
			cnt[a[t]]=0;
			if(b[t]!=0)t=b[t];
			else t++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
