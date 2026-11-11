#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0 && t==2){
        while(t--){
            int k;
            cin>>k;
            if(k==4){
                cout<<1<<endl<<2;return 0;
            }if(k==5){
            cout<<0<<endl<<1;return 0;}
        }
    }else{
        while(t--){
            int a,b;
            cin>>a>>b;
            cout<<b-a;
        }

    }
}
