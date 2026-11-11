#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n,m;
int a[N];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1LL,r=0LL;
	int sum=0LL;
	while(r<n){
		while(l<r and m-sum<(a[r+1LL]-a[r])*(r-l+1)){
			sum-=a[r]-a[l];
			l++;
		}
		sum=sum+(a[r+1LL]-a[r])*(r-l+1LL);
		r++;
		ans=max(ans,r-l+1LL);
	}
	cout<<ans<<"\n";
	return 0;
}
