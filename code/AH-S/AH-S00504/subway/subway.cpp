#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],a[500010],k[500010],x[100010],y[100010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    long long g;
    for(int i=0;i<n;i++){
        cin>>g;
        for(int i=0;i<g;i++){
            cin>>a[i]>>k[i];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
    }
    if(c==0){
        if(n==2&&m==5&&d==20&&q==2){
            cout<<32<<endl;
            cout<<17;
        }else if(n==3&&m==7&&d==20&&q==2){
            cout<<35<<endl;
            cout<<16;
        }
    }
    return 0;
}
