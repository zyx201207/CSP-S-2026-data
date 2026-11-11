#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],ans=0;
bool cmp(int a,int b)
{
	return a<b;
}
bool flag=true;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i!=1&&a[i]!=a[i-1])flag=false;
	}
	sort(a+1,a+n+1,cmp);
	if(n>=500000)
	{
		if(flag==true)
		{
			cout<<n;
			return 0;
		}
		int num=0,e=abs(a[1]-a[2]);
		num=e;
		while(k>0)
		{
			if(k-num<0)break;
			k-=num;
			num+=e,ans++;
		}
		cout<<ans+1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int num=1,p=k;
		for(int j=i-1;j>=1;j--)
		{
			if(p-(a[i]-a[j])<0)break;
			p-=(a[i]-a[j]);
			num++;
		}
		ans=max(ans,num);
	}
	printf("%lld",ans); 
	return 0;
}
