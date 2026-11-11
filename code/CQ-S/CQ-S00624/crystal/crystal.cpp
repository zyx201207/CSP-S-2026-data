#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 40;
long long n,m,a[maxn],s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	long long ans=0;
	for(int i=1;i<=n;++i){
		long long l=1,r=i,now=i;
		while(l<=r){
			long long mid=(l+r)>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m){
				now=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans<<'\n';
}
