#include<cstdio>
int a[200010];
char s[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	scanf("%d",&n);
	long long l=0,r=1;
	int ll=1,rr=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&s[i]);
		r+=a[i];
	}
	long long N=r;
	int cur=0;
	char zf='\0';
	while(l<r)
	{
		if(l>N-r)
		{
			r-=a[rr];
			if(a[rr]<cur)
			{
				cur-=a[rr];
				if(s[rr]!=zf)ans+=a[rr];
			}
			else
			{
				if(s[rr]!=zf)ans+=cur;
				cur=a[rr]-cur;
				zf=s[rr];
			}
			rr--;
		}
		else if(l<N-r)
		{
			l+=a[ll];
			if(a[ll]<cur)
			{
				cur-=a[ll];
				if(s[ll]!=zf)ans+=a[ll];
			}
			else
			{
				if(s[ll]!=zf)ans+=cur;
				cur=a[ll]-cur;
				zf=s[ll];
			}
			ll++;
		}
		while(cur==0&&l<r)
		{
			l+=a[ll],r-=a[rr];
			if(a[ll]<a[rr])
			{
				if(s[ll]!=s[rr])ans+=a[ll];
				cur=a[rr]-a[ll];
				zf=s[rr];
			}
			else
			{
				if(s[ll]!=s[rr])ans+=a[rr];
				cur=a[ll]-a[rr];
				zf=s[ll];
			}
			ll++;
			rr--;
			if(ll>=rr)//bu nrng yong ==
			{
				l=r+1;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
