#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N],t[N];
int op[N],res[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        memset(op,0,sizeof(op));
        memset(t,0,sizeof(t));
        int cnt = 1;
        for(int k = i;k <= n;k++)
        {
            if(t[a[k]] == 0)
            {
                op[cnt] = a[k];
                t[a[k]]++;
                cnt++;
            }
            else 
            {
                bool f = 0;
                for(int j = 1;j <= cnt;j++)
                {
                    if(f == 1)
                    {
                        t[op[j]]--;
                        op[j] = 0;
                        cnt--;
                    }
                    else if(op[j] == a[k] && f == 0)
                    {
                        f = 1;
                    }
                }
            }
        }
        for(int i = 1;i <= m;i++)
        {
            res[i] += t[i];
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

void CSP_J(int AK)
{
    int RP = 100;
    int Inf = 0x3f3f3f3f;
    RP+=Inf;//!
}