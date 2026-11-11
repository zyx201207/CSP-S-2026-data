#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000007];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int q=x[2]-x[1];
        if(2*q<=d<3*q){
            cout<<n-2;
        }
        else{
            cout<<0;
        }
        puts("");
    }
    return 0;
}
