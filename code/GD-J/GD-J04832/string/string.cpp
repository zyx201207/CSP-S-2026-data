#include<bits/stdc++.h>
#define ll long long
#define N 200010

using namespace std;
ll n, s = 0, ans = 0, h, t, pe, nx;
struct node{
	ll v;
	char c;
}a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		cin >> a[i].v >> a[i].c;
		s += a[i].v;
	}
	h = 1; t = n; pe = a[h].v; nx = a[t].v;
	while(h < t){
		if(a[h].c != a[t].c){
			if(pe > nx){
				ans += nx;
				s -= nx;
				t--;
				pe -= nx;
				nx = a[t].v;
			}else if(pe < nx){
				ans += pe;
				s -= pe;
				h++;
				nx -= pe;
				pe = a[h].v;
			}else if(pe == nx){
				ans += pe;
				s - s - pe - nx;
				t--; h++;
				nx = a[t].v; pe = a[h].v;
			}
		}else{
			if(pe > nx){
				s -= nx;
				t--;
				pe -= nx;
				nx = a[t].v;
			}else if(pe < nx){
				s -= pe;
				h++;
				nx -= pe;
				pe = a[h].v;
			}else if(pe == nx){
				s = s - nx - pe;
				t--; h++;
				nx = a[t].v; pe = a[h].v;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
