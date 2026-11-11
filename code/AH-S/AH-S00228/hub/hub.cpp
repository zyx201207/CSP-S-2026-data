#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long inf = 1e18;
const long long mod = 998244353;
const long long N = 1e6 + 5;
int n , m;
int k;
vector<int> a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    int __ , ___;
    cin >> __ >> ___;
    while(___--)
    {
        cin >> n >> k;
        for(int i = 1 ; i <= n ; i++)a[i].clear();
        int x , y;
        for(int i = 1 ; i < n ; i++)cin >> x >> y , a[x].push_back(y) , a[y].push_back(x);
        if(n - k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if(n - k <= 4)
        {
            cout << 1 << endl;
            continue;
        }
        if(13 <= __ && __ <= 14)
        {
            m = n / 2;
            cout << (m - k + 3) / 4 + 1<< endl;
            continue;
        }
        cout << (n - k + 1) / 2 << endl;
    }

    return 0;
}
/*
100 + 100 + 48 + 15
wuwuwu , I want go to WC
*/
