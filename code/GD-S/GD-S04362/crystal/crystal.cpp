#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
ll a[N],q[N];
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m;
	int n;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		q[i]=q[i-1]+a[i];

	for(int i=2;i<=n;++i){
		int l=1,r=i,mid,cnt=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-q[i-1]+q[mid-1]<=m) r=mid,cnt=r;
			else l=mid+1;
		}
		ans=max(ans,i-cnt+1);
	}
	printf("%d",ans);
	return 0;
}
