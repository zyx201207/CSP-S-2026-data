#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e5;
ll n,m,sum[N],a[N];
bool check(ll len){
	for(int r=len,l=1;r<=n;r++,l++)
		if(a[r]*len-sum[r]+sum[l-1]<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=0,r=n,mid=r+l>>1,ans=0;
	while(l<r){
		mid=r+l>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid;
	}
	cout<<ans;
	return 0;
}
