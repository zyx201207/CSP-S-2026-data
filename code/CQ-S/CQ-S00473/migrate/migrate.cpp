#include<bits/stdc++.h>
using namespace std;
mt19937_64 ran(time(0));
void solve(){
    int a,b;
    cin>>a>>b;
    cout<<ran()%(b+1)<<"\n";
    return ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    
    while(t--)
        solve();

    return 0;
}