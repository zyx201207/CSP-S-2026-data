#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> x(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(x[4]-x[1]>=d){
        int c=x[2]-x[1];
        int cs=x[n]-x[1];
        int ti=cs/c+1;
        cout<<ti-3<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
}
