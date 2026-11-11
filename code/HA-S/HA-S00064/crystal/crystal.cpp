#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N],n,m;
bool check(int mid){
	ll sum=0,mi=LLONG_MAX;
	for(int i=1;i<=n-mid;i++){
		//cout<<i+mid-1<<" "<<i+mid-2<<":"<<i-1<<"\n";
		mi=min(mi,a[i+mid-1]*(mid-1)-(b[i+mid-2]-b[i-1]));
	}
	if(mi<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];//cout<<b[i]<<" ";
	//cout<<"\n";
	ll l=1,r=n,ans=0;
	//cout<<check(4)<<" ";
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}

