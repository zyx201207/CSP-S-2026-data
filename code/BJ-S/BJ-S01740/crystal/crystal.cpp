#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,ans=0,cnt=0,minn=LLONG_MAX,maxn=LLONG_MIN;
ll a[N];
void num(int x){
    ll s=m;
    for(int i=(upper_bound(a+1,a+n+1,x)-a)-1;i>=1;i--){
        if((x-a[i])<=s){
            cnt++;
            s-=(x-a[i]);
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(a[i],minn);
        maxn=max(a[i],maxn);
    }
    sort(a+1,a+n+1);
    ll l=minn,r=maxn;
    if(r<=1e5){
        for(ll i=l;i<=r;i++){
            num(i);
            ans=max(ans,cnt);
            cnt=0;
        }
        cout<<ans<<endl;
    }
    else{
        bool dc=1;
        ll x=a[2]-a[1];
        for(int i=2;i<=n;i++){
            if((a[i]-a[i-1])!=x){
                dc=0;
                break;
            }
        }
        if(dc==1){
            ans=1;
            for(int i=x;i<=m;i+=x){
                m-=i;
                if(m<0) break;
                else ans++;
            }
            cout<<min(ans,n)<<endl;
        }
        else{
            for(ll i=l;i<=r;i++){
                num(i);
                ans=max(ans,cnt);
                cnt=0;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
