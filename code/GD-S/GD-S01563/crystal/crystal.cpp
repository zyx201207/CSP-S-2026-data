#include<bits/stdc++.h>

using namespace std;

template<typename type>
inline void read(type &x){
	
	x = 0;register int gcflag = 0;register char ch = getchar();
	while(!isdigit(ch))gcflag = ch == '-', ch = getchar();
	while(isdigit(ch))x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	while(gcflag){x = -x;break;}
}

const int MAXN = 5e5 + 67;

int n, ans;

long long m, a[MAXN], cf[MAXN];

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cout.tie(0);
	
	read(n);
	read(m);
	for(register int i = 1; i < n + 1; ++i){
		
		read(a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	ans = 1;
	
	for(register long long i = 2, lef = 1, ned = 0, res = 1; i <= n; i++){
		
		res++;
		ned += (a[i] - a[i - 1]) * (i - lef);
		while(ned > m && res){
			
			res--;
			ned -= a[i];
			ned += a[lef];
			lef++;
		}
		while(res > ans){
			
			ans = res;
			break;
		}
	}
	
	cout << ans;
	
	return 0;
}
