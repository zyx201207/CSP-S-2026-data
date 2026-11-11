#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+8;
long long a[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int mx=-1e9;
    for(int i=1;i<=n;i++)
    {
        long long cnt=m;
        int ans=1;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=cnt)
            {
                ans++;
                cnt-=(a[i]-a[j]);
            }
        }
        mx=max(mx,ans);
    }
    cout<<mx;
    return 0;
}
