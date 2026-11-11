#include<bits/stdc++.h>
using namespace std;
using  ll=long long;
const long long maxn=500000;
long long n,m,a[maxn+5];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll mid=n/2;
    ll ans=0;
    ll k=mid;
    while(m>a[mid]-a[k])
    {
        k--;
        ans++;
        m-=a[mid]-a[k];
        if(k==1)
            break;
    }
    ll y=mid+1;
    while(a[y]==a[mid])
    {
        y++;
        ans++;
    }
    for(int i=1;i<=ans;i++)
        a[i]=a[mid];
    while(m>=ans)
    {
        m-=ans;
        for(int i=1;i<=ans;i++)
            a[i]++;
        ll o=ans;
        for(int i=ans;i<=n-ans;i++){
            if(a[o]!=a[1])
                break;
            else
                ans++;
        }
    }
    cout<<ans;
}
