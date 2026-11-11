# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int M = 25;
const int N = 2e6 + 5;
char buffer[M];
inline void read ( int & x) {
	x = 0; bool f = 1;
	char ch = getchar ();
	while ( ! isdigit ( ch)) {
		if ( ch == '-') {
			f = 0;
		}
		ch = getchar ();
	}
	while ( isdigit ( ch)) {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	x = f ? x : - x; 
}
inline void read ( ll & x) {
	x = 0; bool f = 1;
	char ch = getchar ();
	while ( ! isdigit ( ch)) {
		if ( ch == '-') {
			f = 0;
		}
		ch = getchar ();
	}
	while ( isdigit ( ch)) {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	x = f ? x : - x; 
}
inline void write ( ll x) {
	if ( x == 0) {
		putchar ( '0');
		putchar ( '\n');
		return;
	}
	int it = 0;
	while ( x) {
		buffer[++ it] = x % 10 + '0';
		x /= 10;
	}
	for ( int i = it; i > 0; i --) {
		putchar ( buffer[i]);
	}
    putchar ( '\n');
}
int n, far[N];
ll d, p[N];
int dp1[N], dp2[N], dp3[N], dp4[N], dp5[N], dp6[N];
int Ans;
inline void solve () {
    read ( n); read ( d);
    for ( int i = 1; i <= n; i ++) {
        read ( p[i]);
    }
    for ( int i = 1; i <= n; i ++) {
        dp1[i] = dp2[i] = dp3[i] = dp4[i] = dp5[i] = dp6[i] = 0;
    }
    int l = 1;
    for ( int i = 1; i <= n; i ++) {
        while ( p[i] - p[l] > d) {
            l ++;
        }
        far[i] = l;
    }
    for ( int i = 1; i <= n; i ++) {
        // 先转移 dp1,4
        if ( far[i] == i) {
            dp1[i] = dp4[i] = 1;
        } else if ( far[i] + 1 == i){
            dp4[i] = 1 + dp4[i - 1];
            if ( i < n && far[i + 1] > far[i]) {
                dp1[i] = 1 + dp4[i - 1];
            } else {
                dp1[i] = 1;
            }
        } else {
            dp4[i] = dp1[far[i]] + i - far[i];
            if ( i < n) {
                if ( far[i + 1] == far[i]) {
                    dp1[i] = 1;
                } else {
                    dp1[i] = far[i + 1] - far[i] + dp1[far[i]];
                }
            }
        }
        // 再转移dp2,5
        if ( far[i] == i) {
            dp2[i] = dp5[i] = 0;
        } else if ( far[i] + 1 == i) {
            dp5[i] = dp5[far[i]];
            if ( i < n && far[i + 1] > far[i]) {
                dp2[i] = dp5[far[i]];
            }
        } else {
            // case 1 , 只从 fari
            dp5[i] = dp2[far[i]];
            if ( i < n && far[i + 1] > far[i]) {
                dp2[i] = dp2[far[i]];
            }
            // case , 从 fari, fari + 1
            if ( far[i] + 2 == i) {
                dp5[i] += dp6[far[i]];
                if ( i + 1 < n && far[i + 1] > far[i] + 1) {
                    dp2[i] += dp6[far[i]];
                }
            } else {
                dp5[i] += dp3[far[i]];
                if ( i + 1 < n && far[i + 1] > far[i] + 1) {
                    dp2[i] += dp3[far[i]];
                }
            }
        }
        //最后为 dp3,6
        if ( i < n) {
            if ( far[i] < i && far[i + 1] < i) {
                dp6[i] += i - far[i + 1];
                if ( i + 1 < n) {
                    if ( far[i + 2] < i) {
                        dp3[i] += far[i + 2] - far[i + 1];
                    } else {
                        dp3[i] += i - far[i + 1];
                    }
                }
                if ( far[i] == far[i + 1]) {
                    dp6[i] += dp1[far[i]] - 1;
                    if ( i + 1 < n && far[i + 2] > far[i + 1]) {
                        dp3[i] += dp1[far[i]] - 1;
                    }
                }
                if ( far[i] + 1 == far[i + 1] && far[i + 1] == i) {
                    dp6[i] += dp6[far[i]];
                    if ( i + 1 < n && far[i + 2] > far[i + 1]) {
                        dp3[i] += dp6[far[i]];
                    }
                }
            }
        }
    }
    Ans = 0;
    for ( int i = 1; i <= n; i ++) {
        if ( far[i] == i) {

        } else if ( far[i] + 1 == i) {
            Ans += dp5[far[i]];
        } else if ( far[i] + 2 == i) {
            Ans += dp2[far[i]];
            Ans += dp6[far[i]];
        } else {
            Ans += dp2[far[i]];
            Ans += dp3[far[i]];
        }
    }
    write ( Ans);
}
signed main () {
	freopen ( "migrate.in", "r", stdin); freopen ( "migrate.out", "w", stdout); 
//    ios :: sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int c, T;
    read ( c); read ( T);
    while ( T --) {
        solve ();
    }
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
10 285714285714285708
*/
