#include<bits/stdc++.h>
using namespace std;
long long n,t,c,m,a[100010],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[2]-a[1]>d){
            cout<<0<<"\n";
            continue;
        }
        cout<<n/d<<"\n";
    }
    return 0;
}
