#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int T,c;
int n;
ll D;
ll x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>D;
        for(int i=1;i<=n;i++) cin>>x[i];
        if((n&1) && (D&1)) cout<<0<<endl;
        else if(!(n&1) && !(n%D==0)) cout<<0<<endl;
        else if(n>=4) cout<<n-3<<endl;
        else cout<<"0\n";
    }
    return 0;
}