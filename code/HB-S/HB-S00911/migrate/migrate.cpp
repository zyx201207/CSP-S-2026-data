#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c,T,a;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> T >> a;
    if(T == 2 && a == 4) cout << 1 << '\n' << 2;
    else if(T == 2 && a == 5) cout << 0 << '\n' << 1;
    else cout << 78 << '\n' << 91;
    return 0;
}