#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n;
ll x[2000005],d,f[2000005],a[2000005],ans;
int L[2000005],l,r,mid,dis[2000005],s,t;
void solve() {
	ans=0;
	for(int i=2;i<=n;i++) {
		if(x[i]-x[i-1]>d) {
			L[i]=i;
			continue;
		}
		l=1,r=i-1;
		while(l<r) {
			mid=(l+r)>>1;
			if(x[i]-x[mid]>d) {
				l=mid+1;
			}
			else {
				r=mid;
			}
		}
		L[i]=l;
	}
	for(int i=1;i<n;i++) {
		a[i-1]=0;
		a[i]=f[i]=1;
		dis[i]=0;
		s=t=i;
		for(int j=i+1;j<=n;j++) {
			L[j]=max(L[j],i);
			if(L[j]==j) break;
			if(L[j]>s) {
				s=L[j];
				t=s;
				while(t+1<j&&dis[t]==dis[t+1]) {
					t++;
				}
			}
			dis[j]=dis[s]+1;
			f[j]=a[t]-a[s-1];
			a[j]=a[j-1]+f[j];
			//cout<<i<<" "<<j<<" "<<f[j]<<" "<<s<<" "<<t<<endl;
			if(f[j]==2) ans++;
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) {
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) {
			scanf("%lld",x+i);
		}
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}
