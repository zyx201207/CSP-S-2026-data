#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
bool cmp(ll a,ll b){
    int lowa=(ll)log2(a);
    int lowb=(ll)log2(b);
    ll diffa=(1<<lowa+1)^a;
    ll diffb=(1<<lowb+1)^b;
    if(diffa!=diffb)return diffa>diffb;
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    vector<ll>b;
    for(int i=0,x;i<n;i++){
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(),b.end(),cmp);
    ll best=-1;
    for(int i=0;i<n-m+1;i++){
        ll ans=b[i];
        for(int j=1;j<m;j++){
            ans&=b[i+j];
        }
        best=max(ans,best);
    }
    cout << best << "\n";
    return 0;
}
