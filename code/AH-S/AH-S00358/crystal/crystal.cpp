#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const int maxn = 5e5+10;

int n;
ll m;
ll a[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	ll sum=0;
	ll cnt=1;
	ll ans=0;
	
	int l=1;
	for(int r=1;r<=n;r++,cnt++){
		while(a[r+1]==a[r]) r++,cnt++;
		ans=max(ans,cnt);
		//cout<<l<<" "<<r<<" "<<sum<<" "<<cnt<<"\n";
		while(sum+cnt*(a[r+1]-a[r]) > m){
			--cnt;
			sum-=a[r]-a[l];
			++l;
		}
		
		sum=sum+cnt*(a[r+1]-a[r]);
	}
	cout<<ans<<"\n";
	return 0;
}
//diff ./crystal.out ./crystal
