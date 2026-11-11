#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll d[N],rd[N],a[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	ll dc;
	bool flag=true;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i<=2) dc=a[i]-a[i-1];
		else{
			if(a[i]-a[i-1]!=dc) flag=false;
		}
	}
	sort(a+1,a+n+1); 
	ll sum=1;
	if(flag){
		ll tmp=m;
		for(ll i=1;i<n;i++){
			if(tmp-dc*i>=0){
				tmp-=dc*i;
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	ll ans=-1;
	for(ll i=1;i<=n;i++){
		d[i]=-1;
		for(ll j=i-1;j>=1;j--){
			d[j]=a[i]-a[j];
		}
//		for(int j=1;j<=n;j++){
//			cout<<d[j]<<" ";
//		}
//		cout<<endl;
		ll tmp=m,cnt=1;
		for(ll j=i-1;j>=1;j--){
			if(tmp-d[j]>=0){
				tmp-=d[j];
				cnt++;
			} 
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
} 
