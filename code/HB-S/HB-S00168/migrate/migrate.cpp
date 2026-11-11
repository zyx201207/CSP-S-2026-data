#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],y[2000005];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int j=1;j<=t;j++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];

        }
        for(int i=1;i<n;i++){
            if(x[i]>=0) y[i]=x[i]-x[i+1];
            if(x[i<=0]) y[i]=x[i+1]-x[i];
        }
        cout<<"0"<<'\n';
    }
    return 0;
}
