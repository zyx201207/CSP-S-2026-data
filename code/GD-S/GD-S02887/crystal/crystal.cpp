#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],sum[N],m;
int ans,n;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) sum[i]=a[i]+sum[i-1];
	rep(i,1,n){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-sum[i-1]+sum[mid-1]<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
