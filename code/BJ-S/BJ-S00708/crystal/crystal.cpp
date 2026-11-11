#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll read(){
    ll igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}

const ll maxn=int(5e5+5);

ll n,m;
ll a[maxn];
ll pre[maxn];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i+1;
        while(l<r){
            ll mid=(l+r)>>1;
            if((i-mid)*a[i]-(pre[i-1]-pre[mid-1])<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
