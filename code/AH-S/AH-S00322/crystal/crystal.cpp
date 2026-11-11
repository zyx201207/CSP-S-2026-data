#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<"\n";
using namespace std;
const int MOD=1e9+7;
ll INF=1e18;
const int N=500005;
int n,m,a[N];
int s[N];
void solve_(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int res=i;
		while(l<=r){
			int mid=(l+r)/2;
			int t=s[i]-s[mid-1];
			if((i-mid+1)*a[i]-t<=m){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int multitest=0,testcase=1;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
