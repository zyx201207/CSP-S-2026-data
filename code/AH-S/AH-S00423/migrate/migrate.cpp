#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,d;
int h[2500010];
int minn,ans;
pair<int,int> f[2500010];

void reset1()
{
    //gunmu
}

void reset2(int to)
{
    ans = 0;
    f[to].second = 1;
    for(int i = 1;i <= n+10;i++) f[i] = make_pair(LLONG_MAX,0);
}

int dfs(int now,int len,int to)
{
    if(len > f[now].first) return 0;
    if(len == f[now].first)
    {
        //searched
        ans += f[now].second;
        return f[now].second;
    }
    if(now == to && len == minn)
    {
        ans++;
        return 1;
    }
    if(len >= minn) return 0;
//for(int i = 1;i <= len;i++) cout << "    ";
//cout << "dfs(" << now << "," <<len << "," << to << ")\n";

    f[now].first = len;

    int sum = 0;
    for(int i = now+1;i <= to;i++)
    {
        if(h[i] - h[now] > d) break;


        sum += dfs(i,len+1,to);
    }
    f[now].second = sum;
    return sum;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,u;
    cin >> c >> u;
    while(u--)
    {
        reset1();
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> h[i];
//cout <<"----------" << n <<endl;
        if(c == 11 || c == 12 || c == 0)
        {
            if(n == 1)
            {
                cout << 0 <<endl;
                continue;
            }
            int k = d / (h[2] - h[1]);
            if(k <= 1) cout << 0;
            else if(n - 2*k + 1 > 0) cout << n - 2*k + 1;
            else cout << 0;
            cout << endl;
        }
	else
        {
            //dfs!
            int cnt_of_ans = 0;

            for(int s = 1;s <= n;s++)
            {
                bool stop = false;
                for(int t = s+1;t <= n;t++)
                {
                    //cutting:can't fly over
                    if(h[t] - h[t-1] > d) break;
                    //cutting:find min road
                    int cnt = 0;
                    int now = s;
                    for(int i = s+1;i <= t;i++)
                    {
                        //now -> i
                        if(h[i] - h[now] > d)//failed
                        {
                            now = i-1;
                            cnt++;
                        }
                    }
                    //cnt: how many place need to rest
                    //so the min length of the way is cnt+1
                    minn = cnt+1;

                    reset2(t);
                    int nothing = dfs(s,0,t);
//cout << s << " to " << t << " :" << minn  << "," << ans << endl;
                    if(ans == 2)
                        cnt_of_ans++;
                }
            }

            cout << cnt_of_ans << endl;
        }
    }
    return 0;
}
