#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,arr[N],suf[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		suf[i]=suf[i-1];
		suf[i]+=arr[i];
	}
	ll mans=0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,ans=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(arr[i]*(i-mid+1)-(suf[i]-suf[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		mans=max(i-ans+1,mans);
	}
	cout<<mans;
	return 0;
}
//? 