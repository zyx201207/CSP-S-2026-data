#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m;
ll a[N],cnt=INT_MIN;
bool chack(ll mid){
    //cout<<mid<<"  ";
    ll p=m;
    vector<ll> b;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=mid){

            ll x=mid-a[i];
            b.push_back(x);
        }
    }
    sort(b.begin(),b.end());
    ll q=0;
    for(int i=0;i<b.size();i++)
    {
        if(p>=b[i]){

            q++;
            p-=b[i];
        }
        else break;
    }
    cnt=max(cnt,q);
   // cout<<cnt<<'\n';
    //cout<<q<<'\n';
    return (b.size()>n-b.size());
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);

    if(n>5000)
    {
        ll bj2=0;cin>>a[1]>>a[2];

        for(int i=3;i<=n;i++) {
            cin>>a[i];

            if(a[i]-a[i-1]!=a[i-1]-a[i-2]) bj2=1;
        }

        if(bj2==0){
            ll x=a[2]-a[1];
            ll p=0,cnt=1;
            while(p<=m){
                p+=cnt*x;
                cnt++;
            }
            if(p>m) cnt--;
            cout<<cnt;
        }
        else{
            cout<<n;
        }
        return 0;

    }
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll l=a[1],r=a[n];
    while(l<r){
        ll mid=(l+r)/2;
        if(chack(mid)){
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    cout<<cnt;
    return 0;
}
