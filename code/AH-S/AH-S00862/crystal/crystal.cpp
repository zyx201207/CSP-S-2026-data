#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,ans,a[N],sum[N];
bool check(int x,int i){
	return a[i]*(i-x)-sum[i-1]+sum[x-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r-1){
			ll mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1; 
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
