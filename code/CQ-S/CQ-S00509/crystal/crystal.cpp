#include<bits/stdc++.h>
#define int long long
#define ll long long
#define maxm 500005
#define maxn 1005
#define msk cerr
#define mod 1000000007
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
namespace Sasuke{
    int cas,T,n,m,ans;
    int a[maxm],s[maxm];
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
        int p=1;
        for(int i=1;i<=n;i++){
            while(p<=i&&a[i]*(i-p+1)-(s[i]-s[p-1])>m)p++;
            ans=max(ans,i-p+1);
        }
        cout<<ans<<"\n";
        return 0;
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    // freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    freopen("ssk.err","w",stderr);
    Sasuke::main();
    msk<<"TIME:"<<clock()/1./CLOCKS_PER_SEC<<"\n";
    return 0;
}
/*
g++ -o crystal crystal.cpp -std=c++14 -Wall -Wl,--stack=200000000 -O2 & .\crystal   
*/