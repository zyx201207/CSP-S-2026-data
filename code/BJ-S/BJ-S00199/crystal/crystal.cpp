#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=0,c=0;
    while(r<n){
        r++;
        c+=(r-l)*(a[r]-a[r-1]);
        while(c>m) c-=(a[r]-a[l]),l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
