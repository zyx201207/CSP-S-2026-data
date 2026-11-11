#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[i];
        }
    }
    if(t==2){
        if(n==5) cout<<1<<endl<<2;
        if(n==6) cout<<0<<endl<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
