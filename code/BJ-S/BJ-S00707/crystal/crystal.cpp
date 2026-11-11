#include<bits/stdc++.h>
using namespace std;
//#define WZH_LOCAL
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int t=1;
const int N=5e5+5;
int n,m;
int a[N];
int r,num;
int ans=1;
signed main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    #ifndef WZH_LOCAL
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif // WZH_LOCAL
    //cin>>t;
    while(t--){
        cin>>n>>m;
        For(i,1,n) cin>>a[i];
        sort(a+1,a+n+1,greater<int>());
        // For(i,1,n) cout<<a[i]<<' ';
        // cout<<'\n';
        For(i,1,n){
            num-=(r-i+1)*(a[i-1]-a[i]);
            if(r<i) r=i,num=0;
            while(r<n&&num+a[i]-a[r+1]<=m){
                r++;
                num+=a[i]-a[r];
            }
            if(r>n) r=n;
            // cout<<i<<' '<<r<<' '<<num<<'\n';
            ans=max(ans,r-i+1);
        }
        cout<<ans;
    }
    return 0;
}