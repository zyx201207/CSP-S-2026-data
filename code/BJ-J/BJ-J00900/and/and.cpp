#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-m];
    return 0;
}