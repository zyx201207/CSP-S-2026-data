#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    bool a[40];
    void read(int x)
    {
        int cur = 0;
        while(x > 0)
        {
            a[++cur] = x & 1;
            x /= 2;
        }
    }
};
Node a[200005];
Node ans;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i].read(x);
        q.push(i);
    }
    int zuigao = 30;
    while(zuigao >= 1)
    {
        queue<int> qq;
        queue<int> qqq;
        int cnt = 0;
        while(!q.empty())
        {
            if (a[q.front()].a[zuigao])
            {
                cnt++;
                qq.push(q.front());
            }
            qqq.push(q.front());
            q.pop();
        }
        if (cnt >= m)
        {
            while(!qq.empty())
            {
                q.push(qq.front());
                qq.pop();
            }
            ans.a[zuigao] = 1;
        }
        else
        {
            while(!qqq.empty())
            {
                q.push(qqq.front());
                qqq.pop();
            }
        }
        zuigao--;
    }
    int fans = 0;
    int b = 1;
    for (int i = 1; i <= 30; i++)
    {
        if (ans.a[i])
        {
            fans += b;
        }
        b *= 2;
    }
    cout << fans;
    return 0;
}
