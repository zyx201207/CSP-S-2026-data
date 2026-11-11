#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    scanf("%lld%lld",&c,&t);
    while(t--){
        int n,d;
        scanf("%lld%lld",&n,&d);
        vector<int>x(n+1);
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        int a=x[2]-x[1];
        int b=d/a;
        int ans=n-b*2+1;
        if(ans<0||ans>=n-1)cout<<"0\n";
        else cout<<ans<<'\n';
    }
    return 0;
}
