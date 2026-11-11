#include<bits/stdc++.h>
using namespace std;

int a[500010],b[500010];
int ans[300010];
int game[500010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;

    bool fl = 1;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] < a[i - 1]) fl = 0;
        if(a[i] > a[i - 1]) b[i] = a[i];
    }

    if(fl == 1)
    {
        for(int i = 1;i <= n;i++)
        {
            if(b[i] != 0) cout << b[i] << " ";
        }
        return 0;
    }


    for(int i = 1;i <= n;i++)
    {
        if(i == n)
        {
            ans[a[i]] ++;
            break;
        }
        
        int o = 1;
        memset(game,0,sizeof(game));

        for(int j = i;j <= n;j++)
        {
            int fl2 = 0;
            for(int k = 1;k <= o;k++)
            {
                if(game[k] == a[j])
                {
                    for(int l = k;l <= o;l++)
                    {
                        game[l] = 0;
                    }
                    o = k;
                    game[k] = a[j];
                    fl2 = 1;
                }
            }
            if(fl2) continue;
            game[j] = a[j];
            o++;
        }

        for(int j = i;j < n;j++)
        {
            ans[game[j]]++;
        }
    }

    for(int i = 1;i <= m;i++)
    {
        if(i == a[n])
        {
            cout << n << " ";
            continue;
        }
        cout << ans[i] << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
