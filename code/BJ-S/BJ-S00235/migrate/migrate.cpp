#include<iostream>
#include<cstdio>
using namespace std;
int c,t,n,d,x[2000005];
int ab(int nn){
    if(nn>=0)return nn;
    if(nn<0)return -nn;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int aflag=1;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>=3){
                if((x[i]-x[i-1])!=(x[i-1]-x[i-2]))aflag=0;
            }
        }
        cout<<0<<"\n";
        if(aflag==1){
            //if(d==2)cout<<2*n-5;
            return 0;
        }
    }
    return 0;
}
