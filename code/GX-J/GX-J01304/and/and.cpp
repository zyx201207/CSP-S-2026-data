#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <=n; i++)
    {

        cin>>a[i];
        f[i] = a[i];
    }
    for(int i = 1; i <= m;i++)
    {
        for(int j = n; j >= m-1;j--)
        {
            f[j] = f[j] *
            for(int z = j;z >= m-1;z--)
            {

                f[j] = max(f[j])
            }
        }
    }
    cout<<f[n];
    return 0;
}
