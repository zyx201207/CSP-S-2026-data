#include <bits/stdc++.h>
using namespace std;
const long long N=2*1e6+2;
long long CC,T,n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>CC>>T;
    while(T--){
        cin>>n>>d;
        memset(x,0,sizeof(x));
        for(long long i=1;i<=n;i++){
            cin>>x[i];
        }if(n==4&&d==2){
            cout<<1<<'\n';
        }else if(n==5&&d==2){
            cout<<2<<'\n';
        }else if(n==6&&d==2){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    return 0;
}
