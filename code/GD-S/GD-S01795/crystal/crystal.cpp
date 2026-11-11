#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=5e5+5;
 
int n;
ll m,a[N],sum[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	rep(i,1,n) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	int l=1;
	int ans=0;
	rep(i,1,n) {
		while(l<=i and sum[i]-sum[l-1]+m<a[i]*(i-l+1))
			l++;
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

*/
