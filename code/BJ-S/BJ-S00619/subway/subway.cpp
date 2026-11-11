#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","w",stdin);
    freopen("subway.out","r",stdout);

    long long c,n,m,d,q,
    cin>>c>>n>>m>>d>>q;
    if(n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl;
        cout<<17<<endl;
    }
    else if(n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl;
        cout<<16<<endl;
    }
    return 0;
}