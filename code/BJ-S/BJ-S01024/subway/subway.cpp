#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10,M = 5e5 + 10;
int c,n,m,d,q;
int w[N],k[N];
int a[510][M],t[510][M];
set<int> st[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][a[i][j]];
            st[a[i][j]].insert(i);
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int ans = w[x] + w[y];
        int strain,ftrain;
        for(int i = 1;i <= n;i++)
        {
            int flag = 0;
            for(int j = 1;j <= k[i];j++)
            {
                if(a[i][j] == x)
                {
                    strain = i;
                    flag++;
                }
                if(a[i][j] == y)
                {
                    ftrain = i;
                    flag++;
                }
                if(flag == 2) break;
            }
            if(flag == 2) break;
        }
        if(strain == ftrain)
        {
            cout << ans + t[strain][x] + t[ftrain][y] << '\n';
            continue;
        }
        int cnt = 0;
        for(int i = 1;i <= m;i++)
        {
            bool flag = 0,flag1 = 0,flag2 = 0;
            cnt = 0;
            for(auto x : st[i])
            {
                cnt++;
                if(x == strain) flag1 = 1;
                if(x == ftrain) flag2 = 1;
                if(flag1 && flag2)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        cout << ans + t[strain][x] + t[ftrain][y] + t[strain][cnt] + t[ftrain][cnt] << '\n';
    }
    return 0;
}
