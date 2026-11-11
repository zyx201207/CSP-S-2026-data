#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define N 100005
using namespace std;

ll rd(){char c=getchar();ll f=1,x=0;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}return f*x;}

int n, c[1000], vis[1000], cnt, k;
vector<int> v[100005];

void dfs(int x)
{
    if (!c[x]) return;
    c[x] = 0;
    for (int i = 0; i < v[x].size(); i++) dfs(v[x][i]);
}
int dfs1(int x, int fa)
{
    if (c[x]) return 0;
    int minn = 1e9;
    for (int i = 0; i < v[x].size(); i++) if (v[x][i] != fa) minn = min(minn, dfs1(v[x][i], x)+1);
    return minn;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int C = rd(), T = rd();
    while (T--)
    {
        n = rd(), k = rd();
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i < n; i++)
        {
            int x = rd(), y = rd();
            v[x].push_back(y), v[y].push_back(x);
        }
        int res = 1e9;
        for (int i = 0; i < (1<<n); i++)
        {
            if (__builtin_popcount(i) != k) continue;
            for (int j = 0; j < n; j++) c[j+1] = (i>>j)&1;
            cnt = 0;
            for (int j = 1; j <= n; j++) if (c[j]) cnt++, dfs(j);
            if (cnt > 2) continue;
            for (int j = 0; j < n; j++) c[j+1] = (i>>j)&1;
            int maxn = -1;
            for (int j = 1; j <= n; j++) maxn = max(maxn, dfs1(j, 0));
            res = min(res, maxn);
        }
        cout << res << '\n';
    }
    return 0;
}
/*
g++ hub.cpp -std=c++14 -O2 -o hub && time ./hub
*/