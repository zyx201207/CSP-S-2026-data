#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005]{};
long long z[500005]{};
long long cnt[500005]{};//
long long o = 0;//pai shu xia biao
long long last;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(long long i = 1;i <= n;i++)//ju
    {
        for(long long j = i;j <= n;j++)//pai
        {
            o++;
            z[o] = a[j];
        }
        for(long long j = 1;j <= o;j++)
        {
            for(long long k = j + 1;k <= o;k++)
            {
                if(z[j] == z[k])
                {
                    for(long long p = j + 1;p <= k;p++)
                    {
                        z[p] = 0;
                    }
                }
            }
        }
        for(long long j = 1;j <= o;j++)
        {
            cnt[z[j]]++;
            z[j] = 0;
        }
        o = 0;
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
