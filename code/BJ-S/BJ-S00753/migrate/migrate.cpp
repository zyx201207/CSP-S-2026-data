#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long x[2000005],n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[i];
        }
        if(n%2==0&&d%2==0) cout<<1<<endl;
        if(n%2==1&&d%2==1) cout<<0<<endl;
        if((n%2==0&&d%2==1)||(n%2==1&&d%2==0)) cout<<2<<endl;
    }
    return 0;
}
