#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,ma=0;
ll a[400010];
char c[400010];
ll try_25(){
    string s;
    ll ans=0;
    for(ll i=1;i<=n;i++)s+=c[i];
    ll l=0,r=n-1;
    while(l<=r){
        if(s[l]!=s[r])ans++;
        l++,r--;
    }
    return ans;
}
ll fun(){
    ll l=1,r=n,ans=0;
    ll bl=a[1],br=a[n];
    while(l<=r){
        if(c[l]==c[r]){
            ll dlt=min(bl,br);
            bl-=dlt,br-=dlt;
            if(bl==0){
                l++;
                bl=a[l];
            }
            if(br==0){
                r--;
                br=a[r];
            }
        }
        else{
            ll dlt=min(bl,br);
            ans+=dlt;
            bl-=dlt,br-=dlt;
            if(bl==0){
                l++;
                bl=a[l];
            }
            if(br==0){
                r--;
                br=a[r];
            }
        }
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll sum=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        ma=max(ma,a[i]);
    }
    if(n<=1)cout<<0;
    else if(n<=2)cout<<(c[1]==c[2]?0:min(a[1],a[2]));
    else if(ma<=1)cout<<try_25();
    else cout<<fun();
    return 0;
}
