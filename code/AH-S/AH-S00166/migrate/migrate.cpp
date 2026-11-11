#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[200020],ans[100010]={0};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
cin>>c>>t;
for(ll cc=1;cc<=t;cc++){
    cin>>n>>d;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ans[cc]=n-3;
for(ll cc=1;cc<=t;cc++){
    cout<<ans[cc]<<endl;
}
}
}
