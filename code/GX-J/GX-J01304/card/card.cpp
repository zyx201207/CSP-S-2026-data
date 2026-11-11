#include<bits/stdc++.h>
using namespace std;
int cnt[300005],n,a[500005],sp[300005],z[300005],now,m;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {

        cin>>a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {

            z[j] = -1;
            sp[j] = -1;
        }
        now = 0;
        for(int j = i; j <= n; j++)
        {
            if(sp[a[j]]!= -1 && sp[a[j]] <= now)
            {

                now = sp[a[j]];

            }
            else{
                now++;
                z[now] = a[j];
                sp[a[j]] = now;
            }

        }

        for(int j = 1; j <= now; j++)
        {

            cnt[z[j]]++;
        }

    }
    for(int i = 1; i <= m; i++)
    {

        cout<<cnt[i]<<" ";
    }
    return 0;
}
