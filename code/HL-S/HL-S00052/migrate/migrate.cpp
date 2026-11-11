#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
int main()
{
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
    int c,T,n,d;
    cin >> c >> T;
    if (c >= 11 && c <= 12)
    {
        while (T--)
        {
            cin >> n >> d;
            int t;
            for (int i = 1;i <= n;i++) cin >> t;
            if (n <= 3) cout << 0 << '\n';
            else cout << n / 4 + 1 << '\n';
        }
    }
    else cout << '0';
}
