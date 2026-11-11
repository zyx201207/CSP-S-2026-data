#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

struct node
{
    long long pos, cost;

    bool operator < (const node &nxt) const
    {
        return cost > nxt.cost;
    }
};

long long c, t;
long long n, d, x[N], res = 0;
long long sum[N];
long long min_cost[N];

priority_queue<node> q;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;

    memset(min_cost, 0x3f, sizeof min_cost);

    while(t --)
    {
        res = 0;

        cin >> n >> d;

        for(int i = 1;i <= n;++ i)
        {
            cin >> x[i];
        }

        for(int i = 1;i <= n;++ i)
        {
            while(q.size()) q.pop();

            q.push(node{i, 0});

            while(q.size())
            {
                node now = q.top();
                q.pop();
                if(sum[now.pos])
                {
                    if(now.cost == min_cost[now.pos])
                    {
                        sum[now.pos] ++;
                    }else
                    {
                        continue;
                    }
                }
                else
                {
                    sum[now.pos] ++;
                    min_cost[now.pos] = now.cost;
                }
                for(int j = i + 1;j <= n;++ j)
                {
                    if(x[j] - x[now.pos] <= d)
                    {
                        q.push(node{j, now.cost + 1});
                    }else
                    {
                        break;
                    }
                }
            }

            for(int j = 1;j <= n;++ j)
            {
                if(sum[j] == 2)
                {
                    res ++;
                }
                if(sum[j])
                {
                    sum[j] = 0;
                }
                if(min_cost[j] != 0x3f3f3f3f)
                {
                    min_cost[j] = 0x3f3f3f3f;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
