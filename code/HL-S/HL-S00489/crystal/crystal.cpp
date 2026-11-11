#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,m1,f=1,ans2=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m1;
    for(int i=1;i<=m1;i++){cin>>a[i];if(a[i]!=i)f=0;}
    if(f)
    {
        while(m1>=ans2)
        {
            m1-=ans2;
            ans2++;
        }
    }
    else
    {
        for(int i=a[1];i<=a[n];i++)
        {
            int x=n,m=m1,ans=0;
            while(a[x]>i)x--;
            while(i-a[x]<=m&&x>0)
            {
                m-=(i-a[x]);
                ans++;
                x--;
            }
            ans2=max(ans2,ans);
        }
    }
    cout<<ans2;
    return 0;
}
