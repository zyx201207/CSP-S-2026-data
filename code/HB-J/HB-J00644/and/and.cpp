#include <bits/stdc++.h>
using namespace std;
#define int long long
#define I return
#define AK 0
#define IOI
int a[200005];
bool ljz[40][200005];
int vis[40];
set <int> s;
string f(int x)
{
    string ans = "";
    while(x != 0)
    {
        int g = x % 2;
        ans = char(g + '0') + ans;
        x /= 2;
    }
    return ans;
}
int mul(int x)
{
    int ans = 1;
    for(int i = 1; i <= x; i++) ans *= 2;
    return ans;
}
bool cmp(int x, int y)
{
    return x > y;
}
signed main()
{
    /*
    wu ri san xing wu shen:
    kai long long hu?
    xie freopen hu?
    guan tong bu liu hu?
    */
   //bu yao ka chang a !!!
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        string s = f(a[i]), llll = "";
        for(int i = 1; i <= 31 - s.size(); i++) llll += '0';
        s = llll + s;
        for(int j = 0; j < s.size(); j++)
        {
            ljz[j][i] = s[j] - '0';
        }
    }
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            vis[i] += ljz[i][j];
        }
    }
    int ans = 0;
    bool flag = 0;
    for(int i = 0; i <= 30; i++)
    {
        if(flag == 0)
        {
            if(vis[i] < m) continue;
            for(int j = 1; j <= n; j++)
            {
                if(ljz[i][j])
                {
                    s.insert(j);
                }
            }
            ans += mul(30 - i);
            flag = 1;
            continue;
        }
        for(int j = 1; j <= n; j++)
        {
            if(ljz[i][j] == 0)
            {
                s.erase(j);
                continue;
            }
            for(int k = 0; k < i; k++)
            {
                if(ljz[k][j] == 0 && vis[k] >= m)
                {
                    s.erase(j);
                    break;
                }
            }
        }
        if(s.size() >= m)
        {
            ans += mul(30 - i);
        }
    }
    cout<<ans;
    I AK IOI;
}//mu luogu uid is:1512077