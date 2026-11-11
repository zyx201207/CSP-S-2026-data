#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int c=0,ans=1;
    int l=1;
    for(int r=1;r<=n;r++){
        c+=(a[r]-a[r-1])*(r-l+1-1);
        while(l<r&&c>m){
            c-=a[r]-a[l];
            l++;
        }
        if(c<=m) ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
