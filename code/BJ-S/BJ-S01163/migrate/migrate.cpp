#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d;
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=n-d/(a[2]-a[1])*2+1;
        if(ans<0||d<=a[2]-a[1])cout<<"0\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
