#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
signed main( ){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=0,r=i,mid;
		while(l<=r){
			mid=l+r>>1;
			if(m>=a[i]*(i-mid)-s[i]+s[mid]) r=mid-1,ans=max(ans,i-mid);
			else l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

