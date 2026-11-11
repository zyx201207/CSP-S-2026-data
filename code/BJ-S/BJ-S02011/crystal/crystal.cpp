//lucky fiiiiiish!
#include<bits/stdc++.h>
#define int long long
#define Test ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],m,nd=0,xnd=0,l=1,ans=0;
signed main(){
    Test
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int r=1;r<=n;r++){
        xnd=xnd+(a[r]-a[r-1])*(r-l);
        while(xnd>m){
            xnd-=(a[r]-a[l]); l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
