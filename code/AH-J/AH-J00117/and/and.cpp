#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll and(ll x,ll y){
    ll a1[1000000005],b1[100000005],c[100000005];
    bool f=true,v=true;
    int c1=1,c2=1,ans=0;
    while(f){
        a1[c1]=x%2;
        c1++;
        x/=2;
        if(x=0){
            f=false;
        }
    }
    while(v){
        b1[c2]=y%2;
        c2++;
        y/=2;
        if(y=0){
            v=false;
        }
    }
    for(int i=1;i<=max(a1.size,b1.size()),i++){
        if(a1[i]==b1[i]){
            c[i]=a1[i];
        }
    }
    for(int i=1;i<=c.size();i++){
        ans+=c[i]*i*2;
    }
    return ans;

}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,k;
    ll a[100000005];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll mx=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            mx=max(and(a[i],a[j]),mx);
        }
    }
    cout << mx;
    return 0;
}
