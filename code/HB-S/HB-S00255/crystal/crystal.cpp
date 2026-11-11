#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int am=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        am=max(am,abs(a[i]));
    }
    if(1ll*am*n<=1e8)
    {
        int ans=-1;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
        {
            int cnt=0,st=m;
            for(int j=1;j<=i;j++)
            {
                if(st>=a[i]-a[j])
                {
                    st-=a[i]-a[j];
                    cnt++;
                }
                else
                {
                    continue;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    else
    {
        int ans=0,st=m;
        sort(a+1,a+1+n);
        int b=(1+n)/2;
        for(int j=1;j<=b;j++)
        {
            if(st>=a[b]-a[j])
            {
                st-=a[b]-a[j];
                ans++;
            }
            else
            {
                continue;
            }
        }
        cout<<ans;
    }
    return 0;
}
