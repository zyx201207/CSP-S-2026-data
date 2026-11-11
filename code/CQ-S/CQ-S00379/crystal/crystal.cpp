#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn],sum[maxn];
void solve(){
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){ 
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){ 
		int l=1,r=i-1,x=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m){
				x=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		} 
		ans=max(ans,i-x+1); 
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
 5 8
 -3 -12 2 7
*/
//我要上迷惑行为大赏！！！！！！！！！ 
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++ss
//RP++
//RP++
//RP++
//RP++

