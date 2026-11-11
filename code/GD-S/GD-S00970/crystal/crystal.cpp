#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 500005;

ll a[MAXN],b[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n,m;
	cin >> n >> m;
	
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	
	sort(a + 1,a + n + 1);
	
	for(int i = 1;i <= n;++i){
		b[i] = a[i] - a[i - 1];
	}
	
	ll l = 1,r = 1,len = 1,ans = 0;
	long long cnt = 0;
	while(l != n){
		if(cnt > m || r == n){
			cnt -= a[r] - a[l];
			++l;
			--len;
		}else{
			++r;
			++len;
			cnt += (len - 1) * b[r];
			while(a[r] == a[r + 1]){
				++r;
				++len;
			}
		}
		if(cnt <= m){
			ans = max(ans,len);
		}
	}
	
	cout << ans;
	
	return 0;
} 

