#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,a[N];
deque<ll> q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll cnt=0,l=1;
    q.push_back(1);
    ll ans=1;
    for(ll i=2;i<=n;i++){
        ll mx=a[q.front()];
        if(a[i]>mx){
            cnt+=(i-l)*(a[i]-mx);
            mx=a[i];
        }
        else{
            cnt+=mx-a[i];
        }
        while(!q.empty()&&a[q.back()]<=a[i])q.pop_back();
        q.push_back(i);
        while(cnt>m){
            cnt-=mx-a[l];
            l++;
            while(!q.empty()&&q.front()<l)q.pop_front();
            if(mx>a[q.front()]){
                cnt-=(i-l+1)*(mx-a[q.front()]);
                mx=a[q.front()];
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}