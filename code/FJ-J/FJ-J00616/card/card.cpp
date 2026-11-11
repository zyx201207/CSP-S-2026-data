#include <bits/stdc++.h>
using namespace std;
int cnt[500005];
int lst[500005];
int a[500005];
int flag[500005];
int main() 
{
	freopen("card3.in","r",stdin);
	freopen("card3.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++) lst[i]=-1;
	for(int i=n;i>=1;i--)
	{
		cnt[a[i]]+=i;
		if(lst[a[i]]!=-1) 
		{
			for(int j=lst[a[i]];j>i;j--)
				if(!flag[j]) cnt[a[j]]-=i,flag[j]=1;
		}
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++)	printf("%d ",cnt[i]);
	return 0;
}
