#include <iostream>
#include <algorithm>
#include <cstdlib>
#define int long long
using namespace std;

const int N=500005;

int a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("crystal/crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }sort(a+1,a+n+1);
    int ans=0,l=1,cost=0;
    for(int i=1;i<=n;++i){
        cost+=(i-l)*(a[i]-a[i-1]);
        while(cost>m){
            cost-=a[i]-a[l];
            ++l;
        }ans=max(ans,i-l+1);
    }cout<<ans;
    return 0;
}
