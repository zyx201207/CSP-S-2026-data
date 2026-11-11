#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll cnt;
ll n,m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    cnt/=n;
    for(ll i=1;i<=n;i++){
        ll x=a[i];
        a[i]=max(x,cnt)-min(x,cnt);
    }
    sort(a+1,a+1+n);
    ll k=0;
    for(int i=1;i<=n;i++){
        if(k+a[i]<m) k+=a[i];
        else if(k+a[i]>=m){
            cout<<i;
            exit(0);
        }
    }
    return 0;
}
