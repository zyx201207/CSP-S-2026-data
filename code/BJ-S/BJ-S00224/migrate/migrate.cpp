#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int a[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(a[n]-a[1]<=d)cout<<0<<endl;
    else if(a[n]-a[1]==2*d)cout<<2<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}
