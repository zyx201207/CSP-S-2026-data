#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=1;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=2,k=0,l=1;r<=n;r++){
		k+=(r-l)*(a[r]-a[r-1]);
		while(k>m){
			k-=a[r]-a[l];
			l++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}
