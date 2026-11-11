#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int x[N];
int dd;
bool flag=1;

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> x[i];
            if(i==2)
            {
                dd=x[i]-x[i-1];
            }
            if(i>2&&x[i]-x[i-1]!=dd)
            {
                flag=0;
            }
        }
        if(flag)
        {
            //cout << dd << endl;
            if(dd>d)
            {
                cout << "0\n";
                continue;
            }
            else
            {
                if(d/dd==1)
                {
                    cout << "0\n";
                    continue;
                }
                int abc=d/dd*2-1;
                cout << max(n-abc,0LL) << "\n";
                continue;
            }
        }
    }
    return 0;
}


