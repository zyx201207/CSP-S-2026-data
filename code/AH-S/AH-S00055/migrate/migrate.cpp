#include <bits/stdc++.h>
using namespace std;
long long c,n,d,t;
unsigned long long m;
long long a[2000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(1){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            m=a[2]-a[1];
            int _=d/m;
            if(_>=2||n<=d*2){
                cout<<n-_<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }
    }else{
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            m=a[2]-a[1];
            if(d<3*m&&d>=2*m){
                cout<<n-3<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }
    }
    return 0;
}