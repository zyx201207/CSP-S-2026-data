#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc() getchar_unlocked()
ll read(){
	ll x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc();
	}
	return x*f;
}
/*
#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<
	pair<ll,ll>,
	null_type,
	less<pair<ll,ll>>,
	rb_tree_tag,
	tree_order_statistics_node_update
> tr;
*/
const int N=2e5+10;
ll n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n,[](ll a,ll b){
		return a>b;
	});
	ll ans=a[1];
	for(ll i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
