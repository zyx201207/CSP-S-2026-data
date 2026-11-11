#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--){
        int n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int v=d/(a[2]-a[1]);
        long long ans=n-(2*v)+1;
        cout<<ans<<'\n';
    }
    return 0;
}
