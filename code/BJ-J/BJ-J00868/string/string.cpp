#include <bits/stdc++.h>
using namespace std;
const int N=300005;
int n;
long long L,a[N],l,r,ans,ll[N],rr[N],ri;
char v[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>v[i];
        L+=a[i];
        ll[i]=rr[i-1]+1;
        rr[i]=rr[i-1]+a[i];
    }
    l=0,r=L,ri=n;
    for(int i=1;i<=n;i++)
    {
        bool bk=0;
        if(l+a[i]>L/2)
        {
            l=L/2;
            bk=1;
        }
        else
        {
            l+=a[i];
        }
        for(int j=ri;j>=1;j--)
        {
            if(ll[j]<L-l+1)
            {
                if(v[i]!=v[j])
                {
                    ans+=r-(L-l+1)+1;
                }
                ri=j;
                r=L-l;
                break;
            }
            else{
                if(v[i]!=v[j])
                {
                    ans+=r-ll[j]+1;
                }
                r=ll[j]-1;
            }
        }
        if(bk) break;
    }
    cout<<ans;
    return 0;
}