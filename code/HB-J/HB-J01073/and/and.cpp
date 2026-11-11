#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll f[100000];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
    }
    sort(f+1,f+n+1,cmp);
    cout<<f[m];
    return 0;
}
