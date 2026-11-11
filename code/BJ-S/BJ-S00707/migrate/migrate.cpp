#include<bits/stdc++.h>
using namespace std;
//#define WZH_LOCAL
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int c,t=1;
const int N=2e6+5;
const int LittleN=5005;
int n,d;
int a[N];
struct node{
    int F,dis;
}dp[LittleN][LittleN];
int ans;
signed main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    #ifndef WZH_LOCAL
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif // WZH_LOCAL
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        For(i,1,n) cin>>a[i];
        if(n<2||a[2]-a[1]>d) cout<<0<<'\n';
        else cout<<n-3<<'\n';
    }
    return 0;
}
