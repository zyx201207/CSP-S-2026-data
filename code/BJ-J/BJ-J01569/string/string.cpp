#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int l,r,n,ln,rn,a[N];
char lc,rc,c[N];
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    l=1,r=n,ln=a[l],lc=c[l],rn=a[r],rc=c[r];
    while(r!=l-1)
    {
        if(ln>rn)
        {
            if(lc!=rc) sum+=rn;
            ln-=rn,r--,rn=a[r],rc=c[r];
        }
        else if(ln<rn)
        {
            if(lc!=rc) sum+=ln;
            rn-=ln,l++,ln=a[l],lc=c[l];
        }
        else
        {
            if(lc!=rc) sum+=rn;
            l++,r--,ln=a[l],lc=c[l],rn=a[r],rc=c[r];
        }
    }
    cout<<sum;
    return 0;
}