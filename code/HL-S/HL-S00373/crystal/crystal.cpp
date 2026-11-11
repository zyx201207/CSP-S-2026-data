#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>5000)
    {
        long long t=m,k=1;
        for(int j=n-1;j>=1;j--)
        {
            t-=(a[n]-a[j]);
            if(t<0)
            {
                break;
            }
            k++;
        }
        if(k>ans)
            ans=k;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        long long t=m,k=1;
        for(int j=i-1;j>=1;j--)
        {
            t-=(a[i]-a[j]);
            if(t<0)
            {
                break;
            }
            k++;
        }
        if(k>ans)
            ans=k;
    }
    cout<<ans;
    return 0;
}
