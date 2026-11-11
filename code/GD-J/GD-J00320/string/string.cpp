#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int N=2e5+10;
int n,ans,a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    For(i,1,n) cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<=r){
        if(a[l]>=a[r]){
            if(c[l]==c[r]) a[l]-=a[r],a[r]=0,r--;
            else ans+=a[r],a[l]-=a[r],a[r]=0,r--;
        } else {
            if(c[l]==c[r]) a[r]-=a[l],a[l]=0,l++;
            else ans+=a[l],a[r]-=a[l],a[l]=0,l++;
        }
    }
    cout<<ans;
    return 0;
}