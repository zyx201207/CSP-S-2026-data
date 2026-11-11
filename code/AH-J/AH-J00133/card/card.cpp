#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;

int n,m;
int a[maxn];
int b[maxn];
int vis[maxn];

/*

282 PTS
COME ON

thick or theat 
i will remember it forever

*/

bool flag_A = 1;

int last_pos[maxn];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last_pos[a[i]] = i;
        if(a[i] < a[i-1]) flag_A = 0;
        // cout << a[i] << " ";
    }
    // cout << endl;

    if(flag_A)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << last_pos[i] << " ";
        }
        return 0;
    }
    
    for (int k = 1; k <= n; k++) // k -> i
    {
        memset(b,0,sizeof(b));
        deque<int> dq_on;
        for (int i = k; i <= n; i++)
        {
            if(b[a[i]] <= 0)
            {
                dq_on.push_back(a[i]);
                b[a[i]] ++;
            }
            else
            {
                int end = a[i];
                while(!dq_on.empty())
                {
                    int back = dq_on.back();
                    dq_on.pop_back();
                    b[back] --;
                    if(back == end) 
                    {
                        break;
                    }
                }
                dq_on.push_back(a[i]);
                b[a[i]] ++;
            }
        }
        // for (int i = 1; i <= m; i++)
        // {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= m; i++)
        {
            vis[i] += (b[i] != 0);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << (int)vis[i] << " ";
    }
    cout << endl;
    
    return 0;
}