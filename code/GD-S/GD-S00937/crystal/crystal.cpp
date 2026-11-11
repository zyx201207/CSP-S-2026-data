#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;

int n,ans=1;
long long m;
long long a[MAXN],s[MAXN],sum[MAXN],ssum[MAXN],sssum[MAXN];

bool check(int x){
	for (int i=2;i+x-2<=n;i++)
		if (sssum[i+x-2]-ssum[i-1]+(sum[n]-sum[i+x-2])*(i-2)<=m) return 1;
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
		s[i]=a[i]-a[i-1];
	for (int i=2;i<=n;i++)
		sum[i]=sum[i-1]+s[i];
	for (int i=2;i<=n;i++)
		ssum[i]=ssum[i-1]+(sum[n]-sum[i-1]);
	for (int i=2;i<=n;i++)
		sssum[i]=sssum[i-1]+s[i]*(i-1);
	int l=1,r=n;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
