#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define zzz ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],pr[N];
ll sum(int l,int r){return pr[r]-pr[l-1];}
bool ck(int l,int r,ll k){
	ll le=r-l+1;
	ll s=k*le-sum(l,r);
	return s<=m;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());//ll
	for(int i=1;i<=n;i++)pr[i]=pr[i-1]+a[i]; 
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			//cout<<l<<' '<<r<<'\n';
			int mid=l+r>>1;
			if(ck(i,mid,a[i]))l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,l-i);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	zzz;solve();
}
/*
2 1
1 2
*/

