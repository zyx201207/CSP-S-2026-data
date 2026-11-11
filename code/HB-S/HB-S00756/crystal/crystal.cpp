#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
bool check(int x){
    int cst=0;
    for(int i=1;i<=x;++i){
        cst+=a[x]-a[i];
    }
    if(cst<=m) return true;
    else return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n); int cst=0,k=2;
    int l=1,r=n,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans; return 0;
}