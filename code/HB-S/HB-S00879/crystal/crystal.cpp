#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
ll s[1000005];
ll n,m;

ll need(ll l,int r){
    return (r-l)*a[r]-(s[r-1]-s[l-1]);
}

ll explore(ll l,ll r){
    ll r0=0;
    ll mid=0;
    bool mark=0;
    while(l<=r){
        //cout << "now between " << l << " ~ " << r << "\n";
        mid=(l+r)/2;
        mark=0;
        for(ll l0=0;l0+mid-1<n;l0++){
            r0=(l0+mid-1);
            if(need(l0,r0)<=m){
                mark=1;
            }
        }
        if(mark==0){
            r=mid;
        }
        else{
            l=mid;
        }
        if(r-l==1){
            break;
        }
    }
    mark=0;
    for(ll l0=0;l0+r-1<n;l0++){
        r0=(l0+r-1);
        if(need(l0,r0)<=m){
            mark=1;
        }
    }
    if(mark==1){
        return r;
    }
    else return l;
}

ll easy(){
    ll r;
    for(ll k=2;k<=n;k++){
        bool mark=0;
        for(ll l=0;l+k-1<n;l++){
            r=(l+k-1);
            if(need(l,r)<=m){
                mark=1;
            }
        }
        if(mark==0){
            return k-1;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    s[0]=a[0];
    for(ll i=1;i<n;i++){
        s[i]=s[i-1]+a[i];
    }
    if(n>5000){
        cout << explore(0,n) << "\n";
    }
    else{
        cout << easy() << "\n";
    }
    return 0;
}
