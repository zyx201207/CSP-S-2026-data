#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9;
ll sj[N];
ll n,m,shu[100100];
ll change(ll a){
	ll ans[N],i=0;
	while(a){
		ans[i]=a%2;
		a/=2;
		i++;
	}
	ll he=0;
	for(int j=i-1;j>=0;j--){
		he=he*10+ans[i];
	}
	return he;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll h=0;
	for(ll i=0;i<n;i++){
		cin>>shu[i];
	}
	sort(shu,shu+n);
	h=change(shu[n-1]);
	for(ll i=n-1;i>=n-1-m;i++){
		h=h&change(shu[i]);
	}
	cout<<h;
	return 0;
}
