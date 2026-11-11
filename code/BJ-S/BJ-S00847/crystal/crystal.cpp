#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int x=1;
    ll o=0;
    int ans=1;
    for(int i=2;i<=n;i++){
        o+=(a[i]-a[i-1])*(i-x);
        while(o>m){
            o-=a[i]-a[x];
            x++;
        }
        ans=max(ans,i-x+1);
    }
    cout<<ans;
    return 0;
}