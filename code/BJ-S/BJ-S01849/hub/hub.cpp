#include<bits/stdc++.h>
#define int long long
using namespace std;
int c , t , n , m , k , u , v , cst , dep[1000005] , mx[1000005] , fa[15] , l , r , mid , anss;
vector<int> mp[1000005];
signed main()
{
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1 ; i < n ; i++)
        {
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        if(c == 1)
        {
            if(n <= k)
            {
                cout << "0\n";
            }
            else
            {
                cout << "1\n";
            }
            continue;
        }
        m = (n + 3) / 2 - k;
        cout << (m + 3) / 4 << '\n';
    }
    return 0;
}
/*
3:48 写了 10 分的暴力。
3:49 怎么现在连最基本的暴力都不会写了。投了。
估分 100 + 100 + 100 + 10 = 310
3:53 好像 n <= 5 答案只会是 1 或 2
估分 100 + 100 + 100 + 15 = 315
检查了 3 题文件读写，然后亭下来了
*/
