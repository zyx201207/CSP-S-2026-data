#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    ans=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=1;
    while( l<=r && r<=n){
        ll k=m;
        for(int i=l;i<=r;i++){
            ll d=a[r]-a[i];
            k-=d;
        }
        if(k>=0){
            ll len=r-l+1;
            ans=max(ans,len);
            r++;
        }
        else l++;
    }
    cout<<ans;
    return 0;
}
//g++ crystal.cpp -o crystal -o2 -std=c++14 -static