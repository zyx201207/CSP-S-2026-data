#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll m;
ll a[500100];
int ans=1;
ll qz[500010];

bool ch(int p,int n)
{
	ll gl=a[n];
	ll sum=qz[n]-qz[p-1];
	ll allsum=1ll*(n-p+1)*gl;
	ll ned=allsum-sum;
	if(ned<=m) return true;
	else return false;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\crystal3.in.txt","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int mn=1e9;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(ch(mid,i))
			{
				mn=min(mn,mid);
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		if(mn!=1e9)
			ans=max(ans,i-mn+1);
	}
	printf("%d",ans);
	return 0;
}
