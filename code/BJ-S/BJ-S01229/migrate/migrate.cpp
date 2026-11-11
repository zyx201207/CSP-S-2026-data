#include<bits/stdc++.h>
using namespace std;
int c,t;
int l[2000100];
int f[2000100];
int g[2000100];
int check(int x,int d)
{
    if(l[x] - d <= l[x-3]) return false;
    if(l[x] - d > l[x-2]) return false;
    if(l[x-1] -d > l[x-3]) return false;
    return true;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        int n,d,ans=0;
        cin >> n >> d;
        for(int i=1 ; i<=n ; i++)
        {
            cin >> l[i];
            f[i] = 0;
            g[i]= false;
        }
        for(int i=1 ; i<=3 ; i++) f[i] = 0;
        for(int i=4 ; i<=n ; i++)
        {
            f[i]= f[i-1];
            if(check(i,d)) f[i]++;
        }
        cout << f[n] << endl;
    }
    return 0;
}
