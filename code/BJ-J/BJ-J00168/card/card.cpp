#include<bits/stdc++.h>
using namespace std;
int a[500005], b[300005], n, m;
bool vis[300005];
void solve(int k)
{
    fill(vis+1, vis+m+1, 0);
    stack<int> s;
    for (int i=k;i<=n;i++)
    {
        if (!vis[a[i]])
        {

            s.push(a[i]);
            vis[a[i]]=1;
        }
        else
        while(!s.empty() && s.top()!=a[i])
        {
            s.pop();
        }
    }
    while(!s.empty())
    {

        b[s.top()]++;
        s.pop();
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
    {
        solve(i);
    }
    for (int i=1;i<=m;i++)
        cout << b[i] << ' ';
}
