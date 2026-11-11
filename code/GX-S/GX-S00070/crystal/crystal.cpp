#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;

int n;

ll a[N],m,s[N];

ll sum(int l,int r){
    return s[r]-s[l-1];
}

bool check(ll x){
    for(int l=1;l<=n-x+1;l++){
        int r=l+x-1;
        if(x*a[r]-sum(l,r)<=m) return true;
    }
    return false;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }

    ll l=1,r=n;

    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }

    cout<<l<<'\n';

    return 0;
}
