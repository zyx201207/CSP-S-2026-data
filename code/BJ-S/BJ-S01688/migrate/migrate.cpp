#include<bits/stdc++.h>
using namespace std;
long long c,t,bcn;
long long n,d;
long long x[4000005];
void solve(){
    cin>>n>>d;
    if(n<=3){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(x[1]+d<=x[3]){
        cout<<0<<endl;
        return;
    }
    if(d>=x[n/2]){
        cout<<0<<endl;
        return;
    }
    bcn=x[1]+d;
    for(int i=1;i<=n;i++){
        if(bcn>=x[i])continue;
        else{
            if(i-1>3){
                cout<<n-i<<endl;
                return;
            }
            if(i-1==3){
                cout<<(n-i)+1<<endl;
            }
            return;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}
