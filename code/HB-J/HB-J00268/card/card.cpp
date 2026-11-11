#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m;
int a[N], sum[M];
int in_stk[M];
stack<int> stk;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1;i <= n;++ i)
    {
        cin >> a[i];
    }

    for(int i = 1;i <= n;++ i)
    {
        for(int j = i;j <= n;++ j)
        {
            if(in_stk[a[j]])
            {
                while(true)
                {
                    int now = stk.top();
                    stk.pop();
                    in_stk[now] --;
                    if(now == a[j]) break;
                }
                stk.push(a[j]);
                in_stk[a[j]] ++;
            }else
            {
                stk.push(a[j]);
                in_stk[a[j]] ++;
            }
        }
        while(stk.size())
        {
            int v = stk.top();
            stk.pop();
            in_stk[v] = 0;
            sum[v] ++;
        }
    }

    for(int i = 1;i <= m;++ i)
    {
        cout << sum[i] << ' ';
    }

    return 0;
}
