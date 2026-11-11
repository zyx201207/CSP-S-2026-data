#include <bits/stdc++.h>
using namespace std;
int a[500010], id[300010], cnt[300010], t[500010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        memset(id, 0 ,sizeof(id));
        memset(t, 0, sizeof(t));
        int pos = 1;
        for(int j = i;j <= n;j++)
        {
            if(id[a[j]] > pos || id[a[j]] == 0 || t[id[a[j]]] != a[j])
            {
                t[pos] = a[j];
                id[a[j]] = pos;
                pos++;
            }
            else
            {
                pos = id[a[j]] + 1;
            }
        }
        for(int j = 1;j < pos;j++)
        {
            cnt[t[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)cout<<cnt[i]<<' ';
    return 0;
}