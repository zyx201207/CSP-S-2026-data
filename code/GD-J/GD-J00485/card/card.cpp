#include<bits/stdc++.h>
using namespace std;
int num[500005];
int n,m;
queue<int> q;
int ed[500005];
int a[500005];
int in[500005];
int f[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i],ed[a[i]] = i + 1;
    for(int i = 1; i <= n; i++)
        in[ed[a[i]]]++,f[i] = 1;
    for(int i = 1; i <= n; i++)
        if(!in[i])
            q.push(i);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        num[a[u]] += f[u];
        in[ed[a[u]]]--;
        f[ed[a[u]]] += f[u];
        if(in[ed[a[u]]] == 0) q.push(ed[a[u]]);
    }
    for(int i = 1; i <= m; i++) 
        cout << num[i] << ' ';
    return 0;
}