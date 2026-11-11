#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int j=1;j<=n;j++) cin>>a[j];
	sort(a+1,a+1+n);
	ll now=0;
	int l=1,r=0;
	for(int j=1;j<=n;j++){
		now+=1ll*(j-l)*(a[j]-a[j-1]);
		while(l<=r&&now>m){
			now-=a[j]-a[l];
			l++;
		}
		r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
