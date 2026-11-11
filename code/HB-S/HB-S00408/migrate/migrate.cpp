#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        long long x=a[n]-a[n-1];
        d/=x;
        if(d<=1)
        {
            cout << "0" << endl;
        }
        else if(n<=2*d-1)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << n-(2*d-1) << endl;
        }
    }
    return 0;
}
