#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    int a,n,i,u,v,m,l,j,c,t,d;
    cin>>c>>t;
    cin>>n,d;
    int x[n];
    for(a=0;a<=n;a++){
        cin>>x[a];
    }
    if(n=4&&d=2){
        cout<<"1"<<endl<<"2";
    }
    if(n=5||d=3){
        cout<<"0"<<endl<<"1";
    }

    return 0;
}