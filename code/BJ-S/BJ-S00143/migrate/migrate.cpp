#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        if(2*(a[2]-a[1])<=m&&m<a[4]-a[1]){
            cout<<n-3<<endl;
        }
    }
    return 0;
}
