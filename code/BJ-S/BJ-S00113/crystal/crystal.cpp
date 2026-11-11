#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,gai=0,ans[500005],mx=-1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    l=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ans[1]=1;
    for(int r=2;r<=n;r++)
    {
        gai+=(a[r]-a[r-1])*(r-l);
        if(gai>m)
        {
            for(int i=l;i<=r;i++)
            {
                if(gai<=m) break;
                else
                {
                    gai-=(a[r]-a[l]);
                    l++;
                }
            }
        }
        ans[r]=(r-l+1);
    }
    for(int i=1;i<=n;i++) mx=max(mx,ans[i]);
    cout<<mx;
    return 0;
}
