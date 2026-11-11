#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
typedef long long ll;
ll n;
ll ans=0;
ll a[N],qzh[N];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		qzh[i]+=a[i]+qzh[i-1];
	}
	ll l=0,r=qzh[n];
	ll x=1,y=n;
	while(l<r){
		if(l>=qzh[x]){
			x++;
		}
		if(r<=qzh[y-1]){
			y--;
		}
		if(s[x]!=s[y]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans<<'\n';
	return 0;
	
}
