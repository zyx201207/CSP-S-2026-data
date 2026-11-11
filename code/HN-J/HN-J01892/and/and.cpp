#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n, m;
int a[MAXN];
//int dp[MAXN];
int ans = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
    	cin >> a[i];
    	ans = max(ans, a[i]);
	} 
	
	
	if (m == 2){ //special1:m=2
		ans = 0;
		for (int i = 1; i <= n; i++){
		    for (int j = i + 1; j <= n; j++){
			    ans = max(a[i] & a[j], ans);
		    }
	    }
	    cout << ans;
	}else if (m == 1){ //special2:m=1
		cout << ans;
	}else if (m == n){
        ans = a[1];
        for (int i = 2; i <= n; i++){
        	ans &= a[i];
		}
		cout << ans;
	}
	
	return 0;
}


