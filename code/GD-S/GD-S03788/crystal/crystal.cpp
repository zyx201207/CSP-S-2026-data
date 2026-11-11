#include<bits/stdc++.h>
using namespace std;
int cnt;
long long n,m,r[500010],ans=1,cha[500010],sum_cha[500010];
bool A=true,B=true;
pair<long long,long long>a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&r[i]);
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i>1&&r[i]==a[cnt].first)
			a[cnt].second++;
		else
		{
			a[++cnt].first=r[i],a[cnt].second=1;
			if(cnt>1)
				cha[cnt]=a[cnt].first-a[cnt-1].first,//cha[1]=0;
				sum_cha[cnt]=cha[cnt]+sum_cha[cnt-1];
		}
		if(r[i]!=i) A=false;		
		if(cnt>3&&cha[cnt]!=cha[cnt-1]) B=false;
		ans=max(ans,a[cnt].second);
	}
//	for(int i=1;i<=cnt;i++)
//		printf("%d %d\n",a[i].first,a[i].second);
	if(m==0) {printf("%lld\n",ans);return 0;}
	if(A) {printf("%lld\n",min(n,m+1));return 0;}
	if(B)
	{
		long long p=m/cha[3];
		for(int i=2;i<=cnt;i++)
		{
			int j=i-1;long long o=p,sum=a[i].second;
			while(1)
				if(j==0)
					break;
				else if(o>=(i-j)*a[j].second)
					o-=(i-j)*a[j].second,sum+=a[j].second,j--;
				else
				{
					sum+=o/(i-j);
					break;
				}
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=2;i<=cnt;i++)
	{
		int j=i-1;long long o=m,sum=a[i].second;
		//printf("\n%d\n",a[i].first);
		while(1)
			if(j==0)
				break;
			else 
			{
				long long x=sum_cha[i]-sum_cha[j];
				//printf("%d  %dppp",sum,x);
				if(o>=x*a[j].second)
					o-=x*a[j].second,sum+=a[j].second,j--;
				else
				{
					sum+=o/x;
					break;
				}
			}
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
} 
