#include<bits/stdc++.h>
using namespace std;
int s[500005],n,m,x,a[300005],b[500005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int d)
{
	while(x<=n)
	{
		s[x]+=d;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int k=0;
	while(x>0)
	{
		k+=s[x];
		x-=lowbit(x); 
	}
	return k;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(a[x]!=0) b[a[x]]=i;
		a[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int x=query(i);
		if(b[i]==0) continue;
		add(i+1,-i-x);
		add(b[i],i+x);
	}
	for(int i=1;i<=m;i++)
	{
		int x=query(a[i]);
		printf("%d ",x+a[i]); 
	}
	return 0;
}

