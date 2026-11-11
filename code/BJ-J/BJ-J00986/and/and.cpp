#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005];
ll mx;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	mx=a[1];
	for(ll i=2;i<=m;i++)mx&=a[i];
	cout << mx;
	return 0;
}