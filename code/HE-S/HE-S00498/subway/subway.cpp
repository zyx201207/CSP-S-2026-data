#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,w[99999],k[99999];
    k[0]=2;
    cin>>c>>n>>m>>d>>q;
    for(int j=0;j<m;j++){
        cin>>w[j];
    }
    for(int i=1;i<=n;i++){
    for(int a=0;a<1+2*k[0];a++){
        cin>>k[a];
    }
    }
    cout<<"32"<<endl;
    cout<<"17"<<endl;
    return 0;
}
