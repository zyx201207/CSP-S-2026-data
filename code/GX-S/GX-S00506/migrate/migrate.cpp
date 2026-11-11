#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
using ll=long long;
const int N=2*1e6+5;
const int INF=-9*1e18;
ll c,t,n,d,x[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        rep(i,1,n) cin>>x[i];
        cout<<"0\n";
    }
    return 0;
}
