#include<bits/stdc++.h>
using namespace std;
long long a[500050];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long ans=0;
    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
    {
        long long fa=0,s=0;
        for(int k=i;k>=1;k--)
        {
            if(s+a[i]-a[k]>m)
            {
                break;
            }
            s+=a[i]-a[k];
            fa++;
        }
        ans=max(fa,ans);
    }
    cout<<ans;
    return 0;
}
