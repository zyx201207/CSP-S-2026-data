#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    long long l=1,r=n,lst=0,rst=0;
    while(l<r)
    {
        if(rst>0)
        {
            if(a[l]>=rst)
            {
                ans+=rst*(c[l]!=c[r]);
                lst=a[l]-rst;
                int trst=rst;rst=0;
                r--;
                if(a[l]==trst)l++;
            }
            else
            {
                ans+=a[l]*(c[l]!=c[r]);
                rst-=a[l];l++;
            }
        }
        else if(lst>0)
        {
            if(a[r]>=lst)
            {
                ans+=lst*(c[r]!=c[l]);
                rst=a[r]-lst;
                int tlst=lst;
                lst=0;
                l++;
                if(a[r]==tlst)r--;
            }
            else
            {
                ans+=a[r]*(c[r]!=c[l]);
                lst-=a[r];r--;
            }
        }
        else
        {
            if(a[l]>=a[r])
            {
                lst=a[l]-a[r];
                ans+=a[r]*(c[l]!=c[r]);
                int tr=r;
                r--;if(a[l]==a[tr]) l++;
            }
            else
            {
                rst=a[r]-a[l];
                ans+=a[l]*(c[l]!=c[r]);l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
