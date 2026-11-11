#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],q[500005],ans[500005],maxx;
bool scar;
bool comp(ll u,ll v){
    return u<v;
}
bool f(ll s,ll e){
    ll all=ans[e]-ans[s]-(q[e]-q[s])*(s-1);
    if(all<=m)
        return 1;
    else
        return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>100000)
            scar=1;
    }
    if(scar==1){
        ll cha=a[2]-a[1];
        ll answ=(sqrt(8.0*m/cha+1)-1)*1.0/2;
        cout<<min(answ,n)<<endl;
        return 0;
    }
    sort(a+1,a+n+1,comp);
    for(int i=2;i<=n;i++)
        q[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++)
        ans[i]=ans[i-1]+(i-1)*q[i];
    for(int i=2;i<=n;i++)
        q[i]=q[i-1]+q[i];
    for(int i=2;i<=n;i++){
        ll l=1,r=i;
        while(l<r){
            ll mid=(l+r)>>1;
            bool c=f(mid,i);
            if(c)
                r=mid;
            else
                l=mid+1;
        }
        maxx=max(maxx,i-l+1);
    }
    cout<<maxx<<endl;
    return 0;
}
