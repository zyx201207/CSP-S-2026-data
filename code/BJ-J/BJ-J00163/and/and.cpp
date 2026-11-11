#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
#define ll long long
ll n,m;
ll a[N];
ll ans;

int main(){
    ios::sync_with_stdio(false);
    freopen("and.in","r",stdin);

    cin>>n>>m;
    for(ll k=1;k<=n;k++)scanf("%d",&a[k]);
    sort(a+1,a+n+1,[](const ll i,const ll j){return i>j;});
    ans=a[1];
    for(ll i=2;i<=m;i++){
        ans&=a[i];
    }freopen("and.out","w",stdout);
    cout<<ans;
    return 0;
}
