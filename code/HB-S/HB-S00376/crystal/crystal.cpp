#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500010];
long long sum_jue[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long sum=0,jue_ping=0,flag,maxn=LONG_LONG_MAX;
    cin>>a[1]>>a[2];
    int k=a[2]-a[1],kk=0;
    for(long long i=3;i<=n;i++)
    {
		cin>>a[i];
		sum+=a[i];
		if(a[i]-a[i-1]!=k)
		{
			kk=1;
		}
	}
	if(n<=5000)
    {
		int ans2=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			ans=1;
			int y=m;
			for(int j=i;j>=1;j--)
			{
				if(a[j]<a[i])
				{
					if(y-(a[i]-a[j])>=0)
					{
						ans++;
						y-=(a[i]-a[j]);
					}
				}
			}
			if(ans>ans2) ans2=ans;
		}
		cout<<ans2;
		return 0;
	}
	if(kk==0)
	{
		long long num=0;
		for(int i=1;;i++)
		{
			num+=i;
			if(num*k>m)
			{
				cout<<i;
				return 0;
			}
		}
		return 0;
	}
    int a1=abs((sum/n)*n),a2=abs((sum/n+1)*n),a3=abs((sum/n-1)*n);
    if(a1>a2&&a1>a3) sum=sum/n;
    if(a2>a1&&a2>a3) sum=sum/n+1;
    if(a3>a1&&a3>a2) sum=sum/n-1;
    for(long long i=1;i<=n;i++)
    {
		sum_jue[i]=abs(a[i]-sum);
		if(sum_jue[i]<maxn)
		{
			flag=i;
			maxn=sum_jue[i];
		}
		jue_ping+=sum_jue[i];
	}
	int aa1=abs((jue_ping/n)*n),aa2=abs((jue_ping/n+1)*n),aa3=abs((jue_ping/n-1)*n);
    if(aa1>aa2&&aa1>aa3) jue_ping=jue_ping/n;
    if(aa2>aa1&&aa2>aa3) jue_ping=jue_ping/n+1;
    if(aa3>aa1&&aa3>aa2) jue_ping=jue_ping/n-1;
	for(long long i=1;i<=n;i++)
    {
		if(sum_jue[i]<=jue_ping&&a[i]<a[flag])
		{
			if(sum_jue[i]==0)
			{
				ans++;
				sum_jue[i]=-1;
				continue;
			}
			if(m-sum_jue[i]<0) break;
			m-=sum_jue[i];
			ans++;
			sum_jue[i]=-1;
		}
	}
	for(long long i=1;i<=n;i++)
    {
		if(m-sum_jue[i]<0||sum_jue[i]<0||a[i]>a[flag]) continue;
		m-=sum_jue[i];
		ans++;
	}
    cout<<ans;
    return 0;
}
// Oct31==Dec25?
