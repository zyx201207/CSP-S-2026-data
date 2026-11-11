#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll cost;
    ll cnt;
};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll a[n]={0};
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    node jz[n];
    ll mx[n]={0};
    memset(jz,0,sizeof(jz));
    for(ll i=0;i<n;i++){
        for(ll o=0;o<n;o++){
            if(a[i]>=a[o]){
                jz[o].cnt=jz[o].cnt+(a[i]==a[o]?1:0);
            }
            else{
                if(abs(a[i]-a[o])>m){
                }
                else if(jz[o].cost+abs(a[i]-a[o])<=m){
                    jz[o].cost=jz[o].cost+abs(a[i]-a[o]);
                    jz[o].cnt=jz[o].cnt+1;
                }
                else{
                    jz[o].cost=abs(a[i]-a[o]);
                    jz[o].cnt=1;
                }
            }
            mx[o]=max(mx[o],jz[o].cnt);
        }
    }
    sort(mx,mx+n);
    printf("%lld",mx[n-1]);
    return 0;
}
