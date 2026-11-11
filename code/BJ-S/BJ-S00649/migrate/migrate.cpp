#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
ll x[2000010];
int cha[2000010];
int a[2000010];
ll n,d;
void solve()
{
    memset(cha,0,sizeof(cha));
    memset(a,0,sizeof(a));
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    int i=1,j=1;
    while(i<=n&&j<=n)
    {
        while(x[j]-x[i]<=d&&j<=n) j++;
        if(i!=j) cha[i]++,cha[j-1]--;
        while(x[j]-x[i]>d&&i<=j) i++;
    }
    for(int i=1;i<=n-1;i++)
    {
        a[i]=a[i-1]+cha[i];
        //cout<<a[i]<<" ";
    }
    int cnt1=0,last=0,cnt2=0;
    ll ans=0;
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]==0)
        {
            ans+=cnt1*last;
            cnt1=last=0;
        }
        else if(a[i]==1)
        {
            cnt1++;
        }
        else if(a[i]==2)
        {
            if(a[i-1]!=2)
            {
                ans+=cnt1*last;
                last=cnt1;
                cnt1=0;
            }
            else if(i>=2&&a[i-2]!=2)
            {
                ans+=last;
                last=1;
            }
            else
            {
                last=1;
            }
        }
        else
        {
            cnt1=cnt2=last=0;
        }
    }
    ans+=cnt1*last;
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C,T;
    cin>>C>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
