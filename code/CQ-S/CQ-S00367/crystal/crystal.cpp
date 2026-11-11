#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
ll a[500005];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    ll res=1,lst=1,cost=0;
    for(ll i=1;i<=n;i++) {
        cost=cost+(i-lst)*(a[i]-a[i-1]);
        while(cost>k) {
            cost-=a[i]-a[lst];
            lst++;
        }
        res=max(res,i-lst+1);
    }
    cout<<res;
    return 0;
}