#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxx=-1,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            ans=a[i];
        }else{
            ans=(ans&a[i]);
        }
        maxx=max(a[i],maxx);
    }
    if(m==1)
    {
        cout<<maxx;
        return 0;
    }
    maxx=-1;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int an=(a[i]&a[j]);
                maxx=max(an,maxx);
            }
        }
        cout<<maxx;
        return 0;
    }
    if(m==n)
    {
        cout<<ans;
        return 0;
    }
    return 0;
}
