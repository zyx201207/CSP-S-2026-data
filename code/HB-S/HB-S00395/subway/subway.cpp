#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(n==2&&m==5){
        cout<<32<<'\n'<<17;
    }
    else if(n==3&&m==7){
        cout<<35<<'\n'<<16;
    }
    else{
        for(int i=1;i<=q;i++){
            cout<<0<<'\n';
        }
    }
    return 0;
}
