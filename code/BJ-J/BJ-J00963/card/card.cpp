#include <iostream>
#include <queue>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    queue<int>q;
    int a[500005] = {};
    int maxn = -1e9;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int box[500005] = {};
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i ; j <= n  ; j++)
        {
            q.push(a[j]);
            if(q.front() == q.back() && q.size() != 1)
            {
                q.pop();
                while(q.front() != q.back() && !q.empty())
                {

                    q.pop();
                }
            }
        }
        while(!q.empty())
        {
            box[q.front()]++;
            q.pop();
        }
    }
    for (int i = 1 ; i <= m ; i++)
    {
        cout << box[i] << " ";

    }
    fcloseall();
    return 0;
}
