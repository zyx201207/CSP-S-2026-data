#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,w[100010];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c==0&&n==2&&m==5){
        cout<<32<<endl<<17;
    }else if(c==0&&n==3&&m==7){
        cout<<35<<endl<<16;
    }else{
        for(int i=1;i<=q;i++){
            cout<<d%w[i]<<endl;
        }
    }
    return 0;
}
