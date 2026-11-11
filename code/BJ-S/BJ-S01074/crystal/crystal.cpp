#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6,INF=0x3f3f3f3f;
typedef pair<ll,ll> PII;

ll n,m;
ll a[N],s[N];

bool check(ll x){
    for(int i=1;i+x<=n;i++){
        if(s[i+x-2]-s[i-1]>=(x-1)*a[i+x-1]-m){
            return true;
        }
    }
    return false;
}

ll find(){
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r)/2+1;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    return l;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    cout<<find();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
