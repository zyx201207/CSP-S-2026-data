#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n,m,c=0,tmp=0,ans=0;
    cin>>n>>m;
    vector<ll> a;
    for(ll i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    for(ll i=1;i<n;i++){
        tmp=i*(a[i]-a[i-1]);
        c=tmp+c;
        if(c>m){
           cout<<ans+1;
           return 0;
        }
        ans++;
    }
    cout<<ans+1;
    return 0;
}
