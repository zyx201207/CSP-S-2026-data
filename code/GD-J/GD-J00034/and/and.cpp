#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
bool bz[200010];
bool cmp(int x,int y)
{
	return x>y;
}
void dg(int x,int y,int cnt)
{
	if(cnt==m)
	{
		ans=max(ans,x&y);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bz[i]==false)
		{
			bz[i]=true;
			dg(x&a[i],a[i],cnt+1);
			bz[i]=false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bz[i]=true;
			bz[j]=true;
			dg(a[i],a[j],1);
			bz[i]=false;
			bz[j]=false;
		}
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
