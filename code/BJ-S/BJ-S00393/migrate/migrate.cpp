#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        long long d,ans=0;
        cin>>n>>d;
        long long x[n+1];
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n==1) cout<<0;
        else if(d>=2*(x[2]-x[1])) cout<<n-3;
        else cout<<0;
        cout<<endl;
    }
    return 0;
}
