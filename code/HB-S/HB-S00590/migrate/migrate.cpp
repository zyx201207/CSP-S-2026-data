#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T;
int n,d;
int a[N];
int f[N];//f[i] =max(r)-->pathlen(i,r)==1
void solve(){
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int l=i,r=n+1;
        while(l<r){
            int mid=(l+r>>1);
            if(a[mid]-a[i]<=d)l=mid+1;
            else r=mid;
        }
        f[i]=l-1; 
    }
    // for(int i=1;i<=n;i++)cerr<<f[i]<<' ';cerr<<'\n';
    for(int i=1;i<=n;i++){
        if(f[i]-i>=2){
            // ans+=f[f[i]-1]-f[f[i]-2]+f[f[f[i]]]-f[f[f[i]-1]];
            ans+=f[f[i]-1]-f[f[i]-2];
            int j=f[i];
            while(f[j]-j>=2){
                ans+=f[f[j]]-f[f[j-1]];
                j=f[j];
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
14:48 t1
16:17 t2
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
