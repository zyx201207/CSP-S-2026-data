#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m,a[N+5],sum[N+5];
inline bool check(int x){
	int l=1,r=x;
	while(r<=n){
		if(a[r]*x-(sum[r]-sum[l-1])<=m) return 1;
		l++,r++;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
