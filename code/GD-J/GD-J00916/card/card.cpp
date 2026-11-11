#include <bits/stdc++.h>

using namespace std;
long long n,m,a[500005],ans[300005];
long long book[300005],yh[500005],beg[300005];
long long koo[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof(book));
		memset(yh,0,sizeof(yh));
		memset(beg,0,sizeof(beg));
		memset(koo,0,sizeof(koo));
		for(int j=i;j<=n;j++)
		{
			book[a[j]]++;
			if(book[a[j]]==1){beg[a[j]]=i;}
			if(book[a[j]]>=2){yh[beg[a[j]]]--,yh[j]++;cout<<beg[a[j]]<<'\n';}
		}
		for(int j=i;j<=n;j++)
		{
			yh[j]+=yh[j-1];
		}
		for(int j=i;j<=n;j++)
		{
			if(yh[j]>=0&&koo[a[j]]==0){koo[a[j]]++;ans[a[j]]++;}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	
	return 0;
}

