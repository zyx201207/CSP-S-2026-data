#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,m,a[N],b;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	ll l=1,r=1;
	ll sum,ans=0;
	while(r!=n&&l<=r){
		sum=0;
		for(int i=l;i<=r;i++){
			sum+=a[r+1]-a[i];
		}
		if(sum>m) l++;
		else if(sum<=m) {ans=max(ans,r-l+2);r++;}
			}
		cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
