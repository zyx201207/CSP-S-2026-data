#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+100;
ll n,m,a[M];
bool check(ll mid){
	ll tot=0;
	for(int i=1;i<=n;i++){
		if(i<mid) tot+=a[mid]-a[i];
		else{
			if(i>mid){
				tot+=mid*(a[i]-a[i-1]);
				tot-=a[i]-a[i-mid];
			}
			if(tot<=m) return 1;
		}
	}
	return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}

