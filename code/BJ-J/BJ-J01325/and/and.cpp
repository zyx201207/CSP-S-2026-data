#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        for(int i=1;i<=n;i++)
            ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    else if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}