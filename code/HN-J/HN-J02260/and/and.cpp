#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll  Q=2e5+5;
ll n,m,l,r,a[Q];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,cmp);

        cout<<a[m];
    return 0;
}

