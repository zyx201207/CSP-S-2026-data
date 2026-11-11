#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],x,ans;
char c[200010];
vector<pair<ll,char>> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<=r){
		if(l==r) break;
		x=min(a[l],a[r]);
		a[l]-=x,a[r]-=x;
		if(c[l]!=c[r]) ans+=x;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
//		cout<<l<<"~"<<r<<" "<<x<<"->"<<ans;
	}
	cout<<ans;
	return 0;
}
