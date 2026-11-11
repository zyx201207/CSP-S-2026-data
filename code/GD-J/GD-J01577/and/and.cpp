#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int dp[N], a[N];
int n, m, maxx;
bool vis[30];
int ans = -1;

int lowbit(int x)
{
    return x & (-x);
}

void dfs(int now, int val)
{
    if(now == m)
        ans = max(ans, val);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(now + 1, val & a[i]);
            vis[i] = 0;
        }
    }
}
void solve1();

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    bool flag = true;//A
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        maxx = max(maxx, a[i]);
        if(lowbit(a[i]) != 1) flag = false;
	}
    if(n <= 20)
    {
        solve1();
        return 0;
    }// 25pts
    if(n <= 2000)
    {
        if(m = 1)
        {
            cout<<maxx;
            return 0;
        }//5pts
        if(m == n)
        {
            int sum = a[1];
            for(int i = 2; i <= n; i++)
                sum = sum & a[i];
            cout<<sum;
            return 0;
        }//5pts
        else
        {
            int maxscore = -1;
            for(int i = 1; i <= n; i++)
            {
                for(int j = i + 1; j <= n; j++)
                {
                    int nowscore = a[i] & a[j];
                    maxscore = max(maxscore, nowscore);
                }
            }
            cout<<maxscore;
        }//15pts;
    }// 25pts
    if( m == n - 1)
    {

    }
    if(flag == true)// 5pts
    {
        sort(a + 1, a + 1 + n, cmp);
        int answer = a[1];
        for(int i = 2; i <= m; i++)
            answer = (answer & a[i]);
        cout<<answer;
        return 0;
    }
    return 0;
}

void solve1()
{
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 1;
        dfs(1, a[i]);
        vis[i] = 0;
    }
    cout<<ans;
}
