#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans=0;
struct node{
    int b;
    string c;
}a[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].b>>a[i].c;
    }
    for(int l=1,cntl=0,r=n,cntr=0;l<r;)
    {
        while(a[l].c==a[r].c)
        {
            if(l>=r) break;
            if(a[l].b-cntl==a[r].b-cntr)
            {
                l++;
                r--;
                cntl=0;
                cntr=0;
            }
            else if(a[l].b-cntl>a[r].b-cntr)
            {
                cntl+=a[r].b-cntr;
                cntr=0;
                r--;
            }
            else if(a[l].b-cntl<a[r].b-cntr)
            {
                cntr+=a[l].b-cntl;
                cntl=0;
                l++;
            }
        }
        if(l>=r) break;
        while(a[l].c!=a[r].c)
        {
            if(l>=r) break;
            if(a[l].b-cntl==a[r].b-cntr)
            {
                ans+=a[l].b-cntl;
                cntl=0;
                cntr=0;
                l++;
                r--;
            }
            else if(a[l].b-cntl>a[r].b-cntr)
            {
                cntl+=a[r].b-cntr;
                ans+=a[r].b-cntr;
                cntr=0;
                r--;
            }
            else if(a[l].b-cntl<a[r].b-cntr)
            {
                cntr+=a[l].b-cntl;
                ans+=a[l].b-cntl;
                cntl=0;
                l++;
            }
        }
        if(l>=r) break;
    }
    cout<<ans;
    return 0;
}
