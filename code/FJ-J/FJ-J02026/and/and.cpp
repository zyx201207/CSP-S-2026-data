#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll> ans(n);
	for(ll i=0;i<n;i++){
		cin>>ans[i];
	}
	sort(ans.begin(),ans.end());
	cout<<ans[n-m];
	return 0;
}
