#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll mx=0,sum=0,ans=-1e9;
    ll l=1;
    for(int r=1;r<=n;r++){
        mx+=(a[r]-a[r-1])*sum;
        sum++;
        while(mx>m){
            mx-=a[r]-a[r-sum+1];
            sum--;
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
