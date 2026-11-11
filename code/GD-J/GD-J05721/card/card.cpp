#include<bits/stdc++.h>
#define N 500005
#define M 300005
using namespace std;
int n,m;
int a[N];
int cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		map<int,int>mp;
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]])for(int k=mp[a[j]];k<j;k++)mp[a[k]]=0;
			mp[a[j]]=j;
		}
		for(int j=1;j<=m;j++)cnt[j]+=(mp[j]!=0);
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	return 0;
}
