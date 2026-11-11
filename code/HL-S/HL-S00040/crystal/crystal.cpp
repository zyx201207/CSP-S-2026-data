#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,l=0,ans=1;
    ll m=0,offset=0;
    cin>>n>>m;
    vector<ll>a(n);
    for(auto &i:a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        m-=(i-l)*(a[i]-a[i-1]);
        offset+=a[i]-a[i-1];
        while(m<0){
            m+=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
