#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
    	cin >> n >> d;
	    for (int i = 1; i <= n; i++)
	        cin >> a[i];
	    int x = d + 1;
	    cout << (n / d - 1) * (x - 2) + (n % d) + 1;
    }
} 
