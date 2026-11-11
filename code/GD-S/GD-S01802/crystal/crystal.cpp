#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int a[N],n;
ll sum[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,pos=0;
		while(l<=r){
			int mid=l+(r-l>>1);
			int len=i-mid+1;
			if(1LL*len*a[i]-(sum[i]-sum[mid-1])<=m){
				pos=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,1LL*i-pos+1);
	}
	cout<<ans<<'\n';
	return 0;
}
