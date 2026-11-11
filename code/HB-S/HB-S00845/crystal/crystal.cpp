#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], cnt;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i=1; i<=n; i++){
    	if (m==0) break;
    	else if (a[i]>a[i-1]) break;
    	else{
    	    a[i]=a[i+1];
    	    m-=a[i+1]-a[i];   
    	}
    	cnt++;
    }
    cout << cnt;
    return 0;
}   
