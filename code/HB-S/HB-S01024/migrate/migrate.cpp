#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+7;
int c,t,n;
long long d,a[N],dp[N],ans = 0;

queue<int> q;

void bfs(int l,int r)
{
    if(a[l] + d >= a[r])
    {
        ans++;
        return ;
    }

    q.push(l);

    for(int i = 1;i <= n;i++)
    {

    }
}


int main()
{
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out", "w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> t;

    while(t--)
    {

        cin >> n >> d;

        for(int i = 1;i <= n;i++) cin >> a[i];

        if(n <= 3)
        {
            cout << 0;
            break;
        }

        ans = 0;

        for(int len = 3;len <= n;len++)
        {
            for(int i = 1;i + len <= n;i++)
            {

            }

        }
    }


    return 0;
}
