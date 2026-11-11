#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll n,m,a[N],ans,c;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll l=1,r=1;r<=n;r++){
        ans=max(ans,r-l+1);
        while(c+(a[r+1]-a[r])*(r-l+1)>m){
            c-=a[r]-a[l];
            l++;
        }
        c+=(a[r+1]-a[r])*(r-l+1);
    }
    cout<<ans;
    return 0;
}
