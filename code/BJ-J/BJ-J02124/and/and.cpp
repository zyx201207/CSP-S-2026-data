#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==n)
    {
        ans=a[1];
        for(int i=1;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)
            ans=max(a[i],ans);
        cout<<ans;
        return 0;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    cout<<a[n-m+1];
    return 0;
}
