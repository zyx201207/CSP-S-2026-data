#include<bits/stdc++.h>

using namespace std;

template<typename type>
inline void read(type &x){
	
	x = 0;register int gcflag = 0;register char ch = getchar();
	while(!isdigit(ch))gcflag = ch == '-', ch = getchar();
	while(isdigit(ch))x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	while(gcflag){x = -x;break;}
}

const int MAXN = 2e6 + 287;
int c, t, n, d, res[MAXN];
long long a[MAXN], dp[MAXN], ans;

void solve1(){
	
	while(t--){
		
		ans = 0;
		read(n);
		read(d);
		for(int i = 1; i <= n; ++i){
			
			read(a[i]);
		}
		
		for(register int i = 1, lef; i <= n; ++i){
			
			lef = i;
			for(register int j = i + 1; j <= n; ++j){
				
				while(a[j] - a[lef] > d)lef++;
				dp[j] = dp[lef] + 1;
				res[j] = 1;
				for(register int k = lef + 1; k <= j; ++k){
					
//					dp[j] = min(dp[j], )
					if(dp[j] == dp[k] + 1)res[j]++;
					else if(dp[j] > dp[k] + 1)res[j] = 1, dp[j] = dp[k] + 1;
				}
				if(res[j] == 2)ans++;// cout << j;
			}
		}
		cout << ans << '\n';
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
signed main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	read(c);
	read(t);
	
	solve1();
	
	return 0;
}
