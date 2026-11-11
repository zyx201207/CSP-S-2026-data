#include<bits/stdc++.h>
using namespace std;
int c,n,k,b,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>n;
    while(n--){
        cin>>k>>b;
        for(int i=1;i<=k;i++){
            cin>>a[i];
        }
        cout<<b<<'\n';
    }
    return 0;
}
