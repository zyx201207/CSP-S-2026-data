#include<bits/stdc++.h>
using namespace std;
//#define WZH_LOCAL
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int c,t=1;
int n,k;
signed main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    #ifndef WZH_LOCAL
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    #endif // WZH_LOCAL
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<k-1<<'\n';
        For(i,1,n-1) cin>>k>>k;
    }
    return 0;
}
