#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    if(m==2)
    {
        int len=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[n])
            {
                cnt[++len]=i;
            }
        }
        for(int i=2;i<=len;i++)
        {
            ans+=cnt[i]-cnt[i-1]-1;
        }
        if(a[n]==1)
        {
            cout<<n<<" "<<ans;
        }
        else
        {
            cout<<ans<<" "<<n;
        }
        return 0;
    }
}