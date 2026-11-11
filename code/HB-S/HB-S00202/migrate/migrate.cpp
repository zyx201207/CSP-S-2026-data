#include<iostream>
#include<cstdio>
using namespace std;
int n,d,x[500005],d0,q,c;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
        bool if_dengcha=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i==1)continue;
            if(i==2){
                d0=x[2]-x[1];
            }
            else if(x[i]-x[i-1]!=d0)if_dengcha=0;
        }
        if(if_dengcha){
            if(d>=2*d0&&d<3*d0){
                cout<<n-3;
            }
            else {
                cout<<0;
            }
        }
        else cout<<0;
        cout<<'\n';
    }
    return 0;
}
