#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e5+5;
ll n,a[N],m;
stack <int> stk;
bool cmp(ll l,ll r){
	return l>r;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
    return 0;
}
