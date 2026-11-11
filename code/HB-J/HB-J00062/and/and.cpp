#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+2];
    int maxa=-1;
    int aabb=2^30-1;
    int max2=-1;
    int ans=2^30-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
        aabb=aabb&a[i];
    }
    if(m==1)
    {
        cout<<maxa;
    }
    else if(m==n)
    {
        cout<<aabb;
    }
    else if(maxa=4)
    {
        cout<<1;
    }
    else
    {
        sort(a+1,a+n+1);
        for(int i=0;i<m;i++)
        {
            ans=ans&a[n+1-i];
        }
        cout<<ans;
    }
}
