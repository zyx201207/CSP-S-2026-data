#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N];
ll diff[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=0;
    for(int i=1;i<=n;i++)
        diff[i]=a[i]-a[i-1];
    int fff=0;
    for(int i=2;i<=n;i++)
    {
        if(diff[i]==diff[2])
            fff++;
        else
            break;
    }
    if(fff==n-1)
    {
        //cout<<"Yes"<<'\n';
        int ans=1;
        ll sum=0;
        for(int i=1;i<n;i++)
        {
            sum+=i;
            if(diff[2]*sum<=m)
                ans++;
            else
                break;
        }
        cout<<ans<<'\n';
    }
    else
    {
        int ans=-114514;
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            int tot=1;
            for(int j=i;j<n;j++)
            {
                cnt+=diff[j+1]*(j-i+1);
                if(cnt>m)
                    break;
                else
                    tot++;
            }
            ans=max(ans,tot);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
