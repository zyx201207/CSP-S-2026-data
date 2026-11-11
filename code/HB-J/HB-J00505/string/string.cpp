#include <bits/stdc++.h>
using namespace std;
struct ll
{
    long long cd;
    char zf;
}f[200003];
long long g;
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>f[i].cd>>f[i].zf;
    }
    for(int l = 1,r = n;l<r;)
    {
        if(f[l].zf!=f[r].zf)
        {
            g+=min(f[l].cd,f[r].cd);
        }
        if(f[l].cd<f[r].cd)
        {
            f[r].cd-=f[l].cd;
            l++;
        }
        else if(f[l].cd>f[r].cd)
        {
            f[l].cd-=f[r].cd;
            r--;
        }
        else
        {
            l++;
            r--;
        }
    }
    cout<<g;
    return 0;
}
