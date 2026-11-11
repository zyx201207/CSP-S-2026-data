#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],qs[500005];
inline bool check(int x,int r){
	return (a[r]*(r-x+1))-(qs[r]-qs[x-1])<=k;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		qs[i]=qs[i-1]+a[i];
		int l=0,r=i;
		while(l+1<r){
			int mid=l+r>>1;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
