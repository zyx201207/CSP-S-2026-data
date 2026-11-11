#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        if(c[l]!=c[r])
        {
                ans+=max(a[l],a[r]);
        }
        else if(l==r-1)
        {
            if(c[l]==c[r])
            {
                ans+=0;
            }
            else
            {
                ans+=min(a[l],a[r]);
            }
        }
        else
        {
            ans+=max(a[l],a[r])-min(a[l],a[r]);
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
