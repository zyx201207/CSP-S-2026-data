#include <bits/stdc++.h>
using namespace std;
int d[2000005];
const int N=2e6+5;
int a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        int n,d,c;
        cin >> n >> d;
        bool flag=1;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            if (n==1)continue;
            if (i==2)c=a[2]-a[1];
            else{
                if (c!=a[i]-a[i-1])
                {
                    flag=0;
                }
            }
        }
        if (flag)
        {
            if (n<=3)
            {
                cout << 0 << endl;
            }
            int k=d/c;
            if (k==0 || k==1)
            {
                cout << 0 << endl;
                continue;
            }
            else{
                if (n==4){
                    cout << 1 << endl;
                    continue;
                }
                cout << n/k << endl;
                continue;
            }
        }
    }
    return 0;
}
