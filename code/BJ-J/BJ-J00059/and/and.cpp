#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,ans,tn[30]={1};
ll maxn1,maxn2,minn=2e30;
struct node{
    ll val,cha;
}a[N];
bool cmp(const node &a,const node&b){
    if(a.val!=b.val)
        return a.val>b.val;
    return a.cha<b.cha;
}
bool cmp1(const node &a,const node&b){
        return a.val<b.val;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].val;
    }
    sort(a+1,a+1+n,cmp1);
    if(m==1){
        cout<<a[n].val;
    }
    else if(m==2){
        ll ans=a[n].val;
        ans&=a[n-1].val;
        cout<<ans;
    }
    else if(m==n){
        ll ans=a[1].val;
        for(ll i=2;i<=n;i++){
            ans&=a[i].val;
        }
        cout<<ans;
    }
    else if(m==n-1){
        ll ans=a[2].val;
        for(ll i=3;i<=n;i++){
            ans&=a[i].val;
        }
        cout<<ans;
    }
    else{
        for(ll i=1;i<=30;i++){
            tn[i]=tn[i-1]*2;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=32;j++){
                if(tn[j]-1-a[i].val>=0){
                    a[i].cha=min(a[i].cha,tn[j]-1-a[i].val);
                }
            }
        }
        sort(a+1,a+1+n,cmp);
        ans=a[1].val;
        for(ll i=2;i<=m;i++){
            ans&=a[i].val;
        }
        cout<<ans;
    }
    return 0;
}
