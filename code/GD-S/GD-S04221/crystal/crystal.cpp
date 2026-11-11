#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
int n;
ll m,a[maxn],sum[maxn];
int ans=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=2,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			ll x=a[i]*mid-(sum[i]-sum[i-mid]);
			if(x<=m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,r);
	}
	cout<<ans<<"\n";
}
