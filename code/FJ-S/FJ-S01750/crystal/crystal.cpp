#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,ans=0,a[N],minn=1e18,maxx=-1e18;
bool check(long long x) {
	long long cnt=0,o=0;
	for(int i=n;i>=1;--i) {
		if(a[i]>x)continue;
		if(a[i]==x){++o;continue;}
		else cnt+=(x-a[i]),++o;
	}
	if(cnt<=m){ans=max(ans,o);return 1;}
	return 0;
}
int main() {
	froepen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],minn=min(minn,a[i]),maxx=max(maxx,a[i]);
	sort(a+1,a+1+n);
	long long l=minn,r=maxx,mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}
