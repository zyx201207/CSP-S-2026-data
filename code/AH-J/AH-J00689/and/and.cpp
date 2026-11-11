#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
    return __builtin_popcount(a)>__builtin_popcount(b);
}
int main(){
    ios::sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,ans;
    cin>>n>>m;
    vector<ll> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num.begin(),num.end(),cmp);
    ans=num[0];
    for(int i=1;i<m;i++)
    ans&=num[i];
    cout<<ans;
    return 0;
}
