#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n, m, a[N], ans[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int time=1;time<=n;time++)
    {
        int table[N], table_r = 0;
        for(int i=time;i<=n;i++)
        {
            bool f = 1;
            for(int j=1;j<=table_r;j++)
                if(table[j] == a[i])
                {
                    f = 0;
                    table_r = j;
                    break;
                }
            if(f)
            {
                table_r++;
                table[table_r] = a[i];
            }
        }
        for(int i=1;i<=table_r;i++)
        {
            ans[table[i]]++;
            //cout<<table[i]<<',';
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
