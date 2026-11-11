#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[500010],s[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll x=a[n],ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=x)
        {
            int flag1=1e9,flag2=1e9;
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]==a[i]) flag1=min(flag1,j);
                if(a[j]==x) flag2=min(flag2,j);
            }
            if(flag1==1e9) ans++;
            else ans+=0;
        }
    }
    if(a[n]==1) cout<<n<<" "<<ans;
    else cout<<ans<<" "<<n;
    return 0;
}
