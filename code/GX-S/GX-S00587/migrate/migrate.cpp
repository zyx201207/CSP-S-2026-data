#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t;
int x[2000005];

void solve1(){
	memset(x, 0, sizeof(x));
    int n, d;
    cin >> n>> d;// The 'd' is the fastest flying distance
    for (int i=1;i<=n;i++)
        cin >> x[i];// The position of the island

    int q= x[n]-x[n-1];
    if (q>d){
        cout << 0<< endl;
        return;
    }

    int tmp=2*(d/q)-1;
    cout << n-tmp<< endl;
    return;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c>> t;
    while (t--){
		 solve1();
    }

    return 0;
}
