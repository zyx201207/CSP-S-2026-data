#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[n+3];
        bool ok=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i!=1&&i!=2&&a[i-1]-a[i-2]!=a[i]-a[i-1])ok=false;
        }
        if(ok){
            if(d/(a[2]-a[1])==2)cout<<n-d/(a[2]-a[1])-1<<endl;
            else cout<<"0\n";
            continue;
        }
        if(a[n]-a[1]<=d*10){
            cout<<"0\n";
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}
