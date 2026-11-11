#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500005],d[500005],maxn=-1,minn=0x3f3f3f3f;
int getans(int i)
{
	for(int j=1;j<i;j++)
	{
		d[j]=a[i]-a[j];//d[j] j号点需要补充的 
	}
	sort(d+1,d+i);//先消最容易的 
	
	int eve=1;//包括i点 
	int mm=m;//临时总和 
	for(int j=1;j<i;j++)
	{
		if(mm>=d[j])//能消
		{
			eve++;
			mm-=d[j];//消掉并扣血 
		} 
		else
		{
			break;
		}
	}
	return eve;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool isd=1,isc=1,is_all=1;
	int cha=0; 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]-a[i-1]!=1)
		{
			isd=0;
		}
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])isc=0;
		cha=a[i]-a[i-1];
		if(a[i]!=a[i-1])is_all=0;
	}
	if(is_all)
	{
		printf("%d",n);
		return 0;
	}
	if(isd)//特殊性质A ai=i
	{
		//cout<<"A!";
		int mm=m,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(mm>=i)
			{
				mm-=i;
			}
			else
			{
				printf("%d",i);
				return 0;
			} 
		} 
	}
	if(isc)//特殊性质B 等差数列 
	{
		//cout<<"B!"; 
		/*此时，当以i为基准时，从i-1至1所需花费为cha+2*cha+3*cha...+cha*(i-1)*/
		int mm=m,ans=1;
		for(int i=cha;i<=n;i+=cha)//同A，枚举所有的d 
		{
			if(mm>=i)
			{
				mm-=i;
				ans++;
			} 
			else
			{
				printf("%d",ans);
				return 0;
			} 
		} 
	} 
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=2;i<=n;i++)//基准:a[i]
	{
		if(a[i]==a[i-1]&&i!=2)
		{
			ans++;
			continue;
		}
		int now=getans(i);
		ans=max(ans,now);
		if(now<ans)
		{
			break;
		}
	}
//	ans=getans(a[n]);
	printf("%d",ans);
	return 0;
}

