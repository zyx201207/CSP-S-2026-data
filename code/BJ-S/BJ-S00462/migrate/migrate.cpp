#include <bits/stdc++.h>
using namespace std;
constexpr size_t N = 2e6+10;
using ull = unsigned long long;
ull land[N],f[N];
ull iter(ull a){
    ull s = 1;
    for(ull i = 1;i<=a;++i){
        s*=i;
    }
    return s;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T,c,n;
    ull m;
    cin>>c>>T;
    while(T--){
        ull mx = 0,mn = LONG_MAX;
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            cin>>land[i];
            //cout<<i<<":"<<land[i]<<" "<<max(mx,land[i])<<" "<<min(mn,land[i])<<endl;
            mx = max(mx,land[i]);
            mn = min(mn,land[i]);
        }
        ull d = (mx-mn)/(n-1);
        ull can = m/d;
        //cout<<d<<" "<<can<<endl;
        if(can<2){
            cout<<0<<"\n";
        }else{
            cout<<n-2<<"\n";
        }
    }
    return 0;
}
