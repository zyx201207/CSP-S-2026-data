#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],l,r,mid,aans,ans,sum[maxn];
long long check(long long x){
	l=1,r=x,aans=0;
	while(l<=r){
		mid=(l+r)/2;
		if((x-mid+1)*a[x]-sum[x]+sum[mid-1]<=m){
			r=mid-1;
			aans=mid;
		}else l=mid+1;
	}
	return x-aans+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)ans=max(ans,check(i));
	cout<<ans<<'\n';
	return 0;
}
