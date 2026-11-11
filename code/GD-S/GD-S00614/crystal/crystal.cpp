#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m,a[N];
bool check(int l,int r){return (a[r]-a[r-1])*(r-l+1)-a[r]+a[l-1]<=m;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) a[i]+=a[i-1];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i,mid;
		for(;l<=r;(mid=l+r>>1,check(mid,i))?r=mid-1:l=mid+1);
		ans=max(ans,i-r);
	}printf("%d",ans);
	return 0;
}
