#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 +5;
int n,m;
int a[maxn],d[maxn];
bool flag[maxn];
bool vis[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i)
    {
        memset(flag,1,sizeof(flag));
        for(int j = i;j <= n;++j)
        {

            for(int k = i;k <= j - 1;++k)
            {
                if(a[j] == a[k] && flag[k] == true)
                {
                    for(int z = k;z <= j - 1;++z)
                    {
                        flag[z] = false;
                    }
                    break;
                }
            }
        }
        for(int j = i;j <= n;++j)
        {
            if(flag[j]){
                //cout << j << " ";
                d[a[j]]++;
            }
        }

    }

    for(int i = 1;i <= m;++i)
    {
        if(d[i] != 0 && vis[i] == false)
        {
            cout << d[i] << " ";
            vis[i] = true;
        }
    }
    return 0;
}
