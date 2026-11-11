#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct duan
{
    long long x;
    char c;
}a[200005];
long long ans;
long long lef,rig;
long long e,f;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
    }
    lef=1;rig=n;
    e=a[lef].x;f=a[rig].x;
    while(lef<rig)
    {
        if(a[lef].c!=a[rig].c)
        {
            ans+=min(e,f);
        }
        if(e>f)
        {
            e=e-f;
            rig--;
            f=a[rig].x;
        }
        else if(e==f)
        {
            lef++;
            rig--;
            e=a[lef].x;
            f=a[rig].x;
        }
        else
        {
            f=f-e;
            lef++;
            e=a[lef].x;
        }
    }
    cout<<ans;
    return 0;
}
