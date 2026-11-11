#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n;
long long m;
long long a[N];
unsigned long long s[N];
int ans;

bool check(int mid,int kkk)
{
	if(a[kkk]*(kkk-mid+1)-(s[kkk]-s[mid-1])<=m) return 1;
	else return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]-=a[1];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
