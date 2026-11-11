#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500010],l[500010],d[500010],s[500010],ans[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = n;i >= 1;i--)
    {
        if(l[a[i]] == 0)
        {
            l[a[i]] = i;
        }
        else{
            d[i] -= i;
            d[l[a[i]]] += i;
            l[a[i]] = i;
        }

    }
    for(int i = 1;i <= n;i++)
    {
        s[i] = s[i - 1] + d[i];
    }
    for(int i = n;i >= 1;i--)
    {

        if(ans[i] == 0)
        {
            ans[i] = i + s[i];
        }
    }
    for(int i = 1;i <= m;i++)cout << ans[i];
}

