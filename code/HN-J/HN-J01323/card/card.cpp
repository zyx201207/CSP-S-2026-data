#include<bits/stdc++.h>
using namespace std;
struct node
{
	int w,id;
}a[500005];
int b[500005],ext[500005],cnt[300005];
bool cmp(node x,node y)
{
	if(x.w==y.w)return x.id<y.id;
	return x.w<y.w;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w;
		b[i]=a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;)
	{
		int x=i+1;
		while(a[x].w==a[i].w)x++;
		if(a[x-1].w==a[i].w)for(int j=i;j<=x-1;j++)ext[a[j].id]=a[x-1].id;
		i=x;
	}
	for(int i=1;i<=n;i++)if(!ext[a[i].id])ext[a[i].id]=a[i].id;
	for(int i=1;i<=n;i++)
	{
		int now=i;
		while(ext[now])
		{
			now=ext[now];
			cnt[b[now]]++;
			now++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
