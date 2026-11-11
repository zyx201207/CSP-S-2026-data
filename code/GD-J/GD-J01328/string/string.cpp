#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
pair<char,ll> a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1,l;i<=n;i++){
		char c;
		cin>>l>>c;
		a[i]={c,l};
		a[i].second+=a[i-1].second;
	}
	ll ans=0,l=1,r=a[n].second,mid=(a[n].second+1)/2;
	int lp=1,rp=n;
	while(l<r){
		ll x=min(a[lp].second,mid)-l+1,y=r-max(a[rp-1].second+1,mid)+1,k=min(x,y);
		l+=k;r-=k;
		if(a[lp].first!=a[rp].first)ans+=k;
		if(l>a[lp].second)lp++;
		if(r<=a[rp-1].second)rp--;
	}
	cout<<ans<<"\n";
	return 0;
}
