#include <bits/stdc++.h>>

using namespace std;
struct sp
{
    int line;
    int st;
    int time;
};
int s[502][21];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c,n,m,d,z;
    cin >> c >> n >> m >> d >> z;
    int a[m+1] = {0};
    for(int i = 1;i <= m;i++)
        cin >> a[i];

    int l[n+1][m];
    int t[n+1][m];
    for(int i = 1;i <= n;i++)
    {
        cin >> l[i][0];
        for(int j = 1;j <= l[i][0];j++)
        {
            int x,y;
            cin >> x >>y;
            l[i][j] = x;
            t[i][x] = y;
            s[x][0]++;
            s[x][s[x][0]] = i;
        }
    }

    int ans[z] = {0};

    for(int k = 0;k < z;k++)
    {
        int x,y;
        cin >> x >> y;
        int mn = a[x] + a[y];
        int mnt[m+1];
        memset(mnt, 1000000, sizeof(mnt));
        mnt[x] = 0;
        queue<sp> q;
        for(int i = 1;i <= s[x][0];i++)
        {
            q.push({s[x][i], x, t[s[x][i]][x]});
        }
        while(!q.empty())
        {
            int l1 = q.front().line;
            int t1 = q.front().time;
            int st1 = q.front().st;
            for(int i = 1;i < l[l1][0];i++)
            {

                if(s[l[l1][i]][0] >= 2)
                {
                    for(int j = 0;j < s[l[l1][i]][0];j++)
                    {
                        if(s[l[l1][i]][j] == l1)
                            continue;
                        int tt = t1 + t[l1][l[l1][i]] + t[s[l[l1][i]][j]][l[l1][i]];
                        if(tt < mnt[l[l1][i]])
                        {
                            mnt[l[l1][i]] = tt;
                            q.push({s[l[l1][i]][j], l[l1][i], tt});
                        }
                    }
                }

                if(t1 + t[l1][l[l1][i]] < mnt[l[l1][i]])
                {
                    mnt[l[l1][i]] = t1 + t[l1][l[l1][i]];


                    if(l[l1][i] == y)
                    {
                        continue;
                    }
                }
            }
            q.pop();
        }
        ans[k] = mnt[y] + mn;
    }
    for(int i = 0;i < z;i++)
        cout << ans[i] << endl;
    return 0;
}
