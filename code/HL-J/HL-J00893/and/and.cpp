#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll a[N][40];
ll flag1[N];
ll flag2[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        ll c;
        cin>>c;
        ll cnt=30;
        while(c>0)
        {
            a[i][cnt]=c%2;
            c/=2;
            cnt--;
        }
    }
    ll flag=0;
    ll ans=0;
    for(int i=1;i<=30;i++)
    {
        int cnt=0;
        if(flag==1)
            for(int j=1;j<=n;j++)
                flag2[j]=max(flag2[j],flag1[j]);
        for(int j=1;j<=n;j++)
        {
            if(flag2[j]==1)
                continue;
            if(a[j][i]==0)
                flag1[j]=1;
            if(a[j][i]==1)
                cnt++,flag1[j]=0;
        }
        if(cnt>=m)
            ans=ans*2+1,flag=1;
        else
            ans=ans*2,flag=0;
    }
    cout<<ans;
    return 0;
}
