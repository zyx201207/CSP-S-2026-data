#include<cstdio>
#include<algorithm>

using std::sort;

constexpr int N=5e5+1;

int n,ans;
long long m,a[N],s[N];

inline long long max(long long x,long long y)
{
	return x>y?x:y;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);

	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];

	for(int i=1;i<=n;++i)
	{
		int l=0,r=i-1,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(s[i]-s[mid]+m>=(i-mid)*a[i])
				r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}

	printf("%d\n",ans);
}




