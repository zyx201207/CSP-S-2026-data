#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
signed main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,lll;i<=n;i++) cin>>lll>>lll;
        int m=(n-1)/2;
        m-=(k/2);
        m/=2;
        int ans=(m+1)*m+k/2;
        ans*=2;
        cout<<ans<<'\n';
    }
    return 0;
}
