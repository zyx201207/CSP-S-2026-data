#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<int , int>

int n , m , cnt[35];
ll a[N];
vector<ll> pre;
vector<ll> now;

int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		ll k = 0;
		for(int j = 0 ; j <= 31 ; j++){
			if((a[i] & (1ll << j))) cnt[j]++;
		}
	}
	ll j = 31 , ans = 0;
	while(j >= 0){
		if(cnt[j] >= m){
			ans += (1 << j);
			for(int i = 1 ; i <= n ; i++){
				if((a[i] & (1ll << j))) pre.push_back(a[i]);
			} 
			break;
		} 
		j--;
	}
	j--;
	while(j >= 0){
		int q = 0;
		now.clear();
		for(int i = 0 ; i < pre.size() ; i++){
			if((pre[i] & (1 << j))) q++;
		}
		if(q >= m){
			ans += (1 << j);
			for(int i = 0 ; i < pre.size() ; i++){
				if((pre[i] & (1 << j))) now.push_back(pre[i]);
			}
			pre = now;
		}
		j--;
	}
	cout << ans << '\n';
	return 0;
} 

/*
FC /W D:\GD-J05342\and\and.ans D:\GD-J05342\and\and.out
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
