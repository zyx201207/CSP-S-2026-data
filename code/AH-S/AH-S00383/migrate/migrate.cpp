#include <bits/stdc++.h>
using namespace std;
int c,T,n,R[2000005];
long long d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while(T--)
    {
        long long num = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> x[i];
        for(int i = 1; i <= n; i++)
            R[i] = upper_bound(x + 1,x + n + 1,x[i] + d) - x - 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 3; j <= n; j++)
            {
                bool vis = false;
                int now = i;
                long long cnt = 0;
                do
                {
                    if(R[now] == now)
                    {
                        vis = true;
                        break;
                    }
                    ++cnt;
                    now = R[now];
                }while(j > now);
                if(vis) continue;
                queue<pair<int,int>> q;
                for(int k = i + 1; k <= R[i]; k++)
                    q.push({k,1});
                long long real = 0;
                while(!q.empty())
                {
                    if(real > 2) break;
                    int id = q.front().first;
                    int rs = q.front().second;
                    q.pop();
                    if(rs > cnt || rs == cnt && id != j) continue;
                    if(rs == cnt && id == j)
                    {
                        real++;
                        continue;
                    }
                    for(int k = id + 1; k <= min(R[id],j); k++)
                        q.push({k,rs + 1});
                }
                if(real == 2) num++;
            }
        }
        cout << num << "\n";
    }
    return 0;
}
