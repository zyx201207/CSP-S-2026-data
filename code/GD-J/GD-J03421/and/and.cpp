#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N(2e5+5);
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	ll n,m;
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll lt = a[n];
	ll sum = 0;
	for(ll i = n;i >= 1;i--){
		if(a[i] < lt){
			lt = a[i];
			sum++;
		}
		if(sum == m-1){
			cout << lt;
			break;
		}
	}
	return 0;
}

