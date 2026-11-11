#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], s,f[10000010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n-1;i++)
    {
        long long k = 0, c = a[i] - a[i-1],w = 1;
        for(int j=i-1;j>=0;j--)
        {
            f[j] += c;
            if(k+f[j]<=m)
            {
                k+=f[j];
                w++;
            }
        }
        if(w>s)
        {
            s = w;
        }
    }
    cout << s;
    return 0;
}
