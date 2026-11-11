#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int a[500005];
int r[300005];
int vis[500005], dis[500005];
stack<int> q;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) //枚举局数
    {
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        //cout << "@@@@@@@@@@@@@@\n";
        int s = i; //起始牌id
        //cout << "####################\n";
        //cout << s << "\n";
        for (int j = s; j <= n; ++j)
        {
            //cout << "!!!!!!!!!!!!!!!!!!!\n";
            if (!vis[a[j]])
            {
                q.push(a[j]);
                vis[a[j]] = 1;
            }
            else
            {
                while (1)
                {
                    int x = q.top();
                    //cout << x << " " << a[j] <<endl;
                    if (x == a[j])
                    {
                        //cout << x << " " << a[j] << "\n";
                        //cout << "&&&&&&&&&&&&&&\n";
                        break;
                    }
                    q.pop();
                    if (a[j] != x) vis[x] = 0;
                    //cout << "************\n";
                }
            }
            //cout << "%%%%%%%%%%%%%\n";
        }
        //cout << "$$$$$$$$$$$$$\n";
        while (!q.empty())
        {
            int x = q.top();
            q.pop();
            if (!dis[x]) r[x]++;
            dis[x] = 1;
        }
        //cout << "^^^^^^^^^^^^\n";
    }
    for (int i = 1; i <= m; ++i) cout << r[i] << " ";
    return 0;
}
