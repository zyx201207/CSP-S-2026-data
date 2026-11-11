#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
map<ll,int> mp1,mp2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool sp=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) sp=0;
        mp2[a[i]]++;
    }
    if(sp){
        ll dif=a[n]-a[n-1];
        ll cnt=0;
        for(int i=1;i<=n;i++){
            if(dif*i*(i+1)/2>m){
                break;
            }
            cnt=i;
        }
        cout<<cnt+1;
        return 0;
    }
    sort(a+1,a+n+1);
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(mp1.count(a[i])) continue;
        mp1[a[i]]=1;
        ll tmp=m,cnt=0;
        for(int j=i-1;j>=1;j--){
            if(a[i]==a[j]) continue;
            if(tmp-(a[i]-a[j])<0){
                break;
            }
            tmp-=a[i]-a[j];
            cnt++;
        }
        ans=max(ans,cnt+mp2[a[i]]);
    }
    cout<<ans;
    return 0;
}