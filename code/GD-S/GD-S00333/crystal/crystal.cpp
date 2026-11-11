#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500004;
int n;ll m;
ll a[maxn];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	ll cst=0;
	for(int i=2,j=1;i<=n;i++){
		cst+=(ll)(i-j)*(a[i]-a[i-1]);
		while(cst>m){
			cst-=a[i]-a[j],j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n'; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	Solve();
	return 0;
}

