// crystal by A67dgt027FxdGT54 (luogu user 1417426)

#include <bits/stdc++.h>
using namespace std;
#define int long long // 10 years OI = GUNMU

int n, m, a[500005];

/*
bool check(int mid){
	int cost = 0;
	for(int i=1;i<=n;i++){
		cost += a[mid] - a[i];
	}
	return cost <= m;
}*/



signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	// double-pointer
	
	int l = 1, r = 1, cost = 0, ans = 0, curAns = 0;
	
	while(l <= n && r <= n){
		if(r == n){
			cost = cost - (a[r] - a[l]);
			l++;
			ans = max(ans, r - l + 1); 
		}
		else{
			int newCost = cost + (r - l + 1) * (a[r+1] - a[r]);
			if(newCost > m){
				cost = cost - (a[r] - a[l]);
				l++;
				ans = max(ans, r - l + 1); 
			}
			else{
				cost = newCost;
				r++;
				ans = max(ans, r - l + 1);
			}
		}
	}
	
	cout << ans;
	
	/*
	
double-pointer?

1 2 3 4 5
1 2 4 8 9, m = 5
E         // 0
l r       // oldCost + (oldR - l + 1) * (a[newR] - a[oldR]) = 0 + (1 - 1 + 1) * (2 - 1) = 1, ans = (newR - l + 1) = 2
l   r     // 1       + (2    - 1 + 1) * (4       - 2      ) = 5, ans = 3
  l r     // oldCost - (a[r] - a[oldL]) = 5 - (4 - 1) = 2, ans = 2
    E     // 2       - (4    - 2      ) = 0, ans = 1
    l r   // 0       + (3    - 3 + 1) * (8       - 4      ) = 4, ans = 2
      E   // 4       - (8    - 4      ) = 0, ans = 1
      l r // 0       + (4    - 4 + 1) * (9       - 8      ) = 1, ans = 2
        E // 1       - (9    - 8      ) = 1, ans = 1
    
	*/
	
	
	/* binary search, WA on sample 3
	
	int l = 1, r = n;
	
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	
	cout << r;
	
	*/
	
	return 0;
}

/*

to save more ops, 
it always chooses a crystal i that make the energy of (~each~ crystal which's energy is less than a[i]) add to a[i].

then, you can merge i crystals.

BE CAREFUL. a MIGHT BE NOT SORTED.

e.g.


    i
1 2 4 8 9
4 4 4 8 9

binary search.

1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
l                   m                   r
                      l       m         r
                      l m   r
                          L r
                        r l
                        
                        
WA. hack:

1 101 102 300 500, m = 1

1 102 102 300 500


double-pointer?

1 2 3 4 5
1 2 4 8 9, m = 5
E         // 0
l r       // oldCost + (oldR - l + 1) * (a[newR] - a[oldR]) = 0 + (1 - 1 + 1) * (2 - 1) = 1, ans = (newR - l + 1) = 2
l   r     // 1       + (2    - 1 + 1) * (4       - 2      ) = 5, ans = 3
  l r     // oldCost - (a[r] - a[oldL]) = 5 - (4 - 1) = 2, ans = 2
    E     // 2       - (4    - 2      ) = 0, ans = 1
    l r   // 0       + (3    - 3 + 1) * (8       - 4      ) = 4, ans = 2



save 15 min to check. (the lesson from j)



*/
