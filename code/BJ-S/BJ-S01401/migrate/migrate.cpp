#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,d;
int x[2000010];
int ans;

void sum(int l,int r,int mid)
{
    ans += (mid - l) * (r - mid - 1);
    return ;
}

void work(int l,int r)
{
    vector<int> g;
    for(int i = l + 1;i <= r - 2;i++)
    {
        if(x[i + 1] - x[i - 1] <= d && x[i + 2] - x[i] <= d)
        {
            g.push_back(i);
        }
    }
    for(int i = 0;i < g.size();i++)
    {
        int L = (i == 0 ? l : g[i - 1]);
        int R = (i == g.size() - 1 ? r : g[i + 1] + 1);
        sum(L,R,g[i]);
    }
    return ;
}

int cnt[5010];
int dis[5010];
int step[5010];

void dfs(int pos,int dep)
{
    dis[pos] = min(dis[pos],dep);
    if(dis[pos] == dep)
    {
        cnt[pos]++;
    }
    if(cnt[pos] > 2)
    {
        return ;
    }
    if(pos == n)
    {
        return ;
    }
    for(int i = step[pos];i >= pos + 1;i--)
    {
        dfs(i,dep + 1);
    }
    return ;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,t;
    cin >> c >> t;
    for(int times = 1;times <= t;times++)
    {
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        if(n <= 3)
        {
            cout << 0 << endl;
        }
        else if(c == 11 || c == 12)
        {
            int k = x[2] - x[1];
            int ts = d / k;
            if(ts <= 1)
            {
                cout << 0 << endl;
            }
            else
            {
                int len = 2 * d / k;
                cout << n - len + 1 << endl;
            }
        }
        else if(c <= 10)
        {
            for(int i = 1;i <= n;i++)
            {
                int j = i + 1;
                step[j] = i;
                while(x[j] - x[i] <= d && j <= n)
                {
                    step[i] = j;
                    j++;
                }
            }
            for(int i = 1;i <= n;i++)
            {
                memset(dis,0x3f,sizeof(dis));
                memset(cnt,0,sizeof(cnt));
                dfs(i,0);
                for(int j = i + 1;j <= n;j++)
                {
                    if(cnt[j] == 2)
                    {
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }
        else
        {
            int last = 1;
            for(int i = 1;i < n;i++)
            {
                if(x[i + 1] - x[i] > d)
                {
                    work(last,i);
                    last = i + 1;
                }
            }
            work(last,n);
            cout << ans << endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
