#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],zhong,zhong1,ans,maxn;
char c[N];
char nm[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        maxn=max(maxn,a[i]);
        zhong+=a[i];
    }
    if(maxn*n<=2000005){
        ll wei=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=a[i];j++){
                nm[++wei]=c[i];
            }
        }
        for(ll i=1;i<=wei/2;i++){
            if(nm[i]!=nm[wei-i+1]){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    zhong=(zhong)/2;
    for(ll i=1;i<=n;i++){
        zhong1+=a[i];
        if(zhong1>=zhong){
            zhong1=i;
            break;
        }
    }
    ll sheng=0,j=n;
    for(ll i=1;i<=zhong1;i++){
        sheng+=a[i];
        while(sheng>=a[j]){
            if(c[i]!=c[j]){
                ans+=a[j];
                sheng-=a[j];
            }
            j--;
        }
    }
    cout<<ans;
    return 0;
}
