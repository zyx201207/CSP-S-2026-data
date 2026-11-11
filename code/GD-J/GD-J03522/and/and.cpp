#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll n , m , a[N];
int cnt[35] ;
vector<int> wit[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	
	for(int i = 1;i <= n;i++)
		for(ll j = 0;j <= 32;j++)
			if( (a[i]>>j)&1ll ) ++cnt[j];
	for(int i = 1;i <= n;i++) wit[32].push_back(i);
	
	ll ans = 0,last = 32;
	for(ll j = 31;j >= 0;j--){
		if( cnt[j] >= m ) {
			ans |= (1ll<<j);
			for(auto x : wit[last]){
				if( (a[x]>>j)&1ll ) wit[j].push_back(x);
				else {
					for(ll p = 0;p < j;p++)
						if( (a[x]>>p)&1ll ) --cnt[p];
				}
			}	
			last = j;
		}
	}
	cout << ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
