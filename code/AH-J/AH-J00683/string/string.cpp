#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200005];
string c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(ll i=n;i>=n/2+1;i--){
        if(i==n-i+1){
            break;
        }
        if(a[i]==a[n-i+1]){
            if(c[i]!=c[n-i+1]){
                ans+=a[i];
            }
        }else{
            if(i-(n-i+1)<=1){
                if(c[i]==c[n-i+1]){
                    break;
                }
            }
            ll pos=0;
            pos=abs(a[i]-a[n-i+1]);
            ans+=pos;

            if(a[i]>a[n-i+1]){
                a[i]-=pos;
                a[i-1]+=pos;
            }else{
                a[n-i+1]-=pos;
                a[n-i+2]+=pos;
            }

            if(c[i]!=c[n-i+1]){
                ans+=a[i];
            }
        }

    }
    cout<<ans;
    return 0;
}
