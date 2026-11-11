#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
const int N=5e5;
int n,m,a[N],x,y,k,cnt,ans;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;cin>>k>>t;while(t--){
        cin>>n>>m;
        fo(i,1,n) cin>>a[i];
        int cha=a[2]-a[1];
        if(2*cha>m) cout<<0;
        else cout<<n-2;
    }
    return 0;
}
