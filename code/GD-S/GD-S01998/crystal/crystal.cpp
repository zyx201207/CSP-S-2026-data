#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    auto check=[&](int x)->bool{
        ll sum=0;
        for(int i=1;i<=x;i++) sum+=a[x]-a[i];
        ll mn=sum;
        for(int i=x+1;i<=n;i++){
            sum-=a[i-1]-a[i-x];
            sum+=(a[i]-a[i-1])*x;
            mn=min(mn,sum);
        }
        return mn<=m;
    };
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}