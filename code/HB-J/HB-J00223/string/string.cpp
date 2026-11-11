#include<bits/stdc++.h>
using namespace std;
#define Int long long
struct str{
    Int si;
    char c;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Int n;
    cin>>n;
    Int cnt=0;
    for(Int i=1;i<=n;i++)
    {
        cin>>a[i].si>>a[i].c;
        cnt+=a[i].si;
    }
    Int l=1,r=n;
    Int lj=a[l].si,rj=a[r].si;
    Int g=0;
    Int ans=0;
    while(lj+rj<=cnt)
    {
        char c1=a[l].c;
        char c2=a[r].c;
        if(c1!=c2)
        {
            ans+=min(lj,rj)-g;
        }
        g=min(lj,rj);
        if(lj<=rj)
        {
            lj+=a[++l].si;
        }
        else{
            rj+=a[--r].si;
        }
    }
    cout<<ans;
    return 0;
}
