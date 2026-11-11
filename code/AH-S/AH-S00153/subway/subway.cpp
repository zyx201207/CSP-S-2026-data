#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a,b,c,d,e,x[500005],sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>a>>b>>c>>d>>e;
    for(int i=1;i<=c;i++){
        cin>>x[i];
    }for(int i=1,t;i<=b;i++){
        cin>>t;
        for(int j=1,r;j<=2*t;j++){
            cin>>r;
            sum+=r;
        }
    }for(int i=1,q,w;i<=e;i++){
        cin>>q>>w;
        cout<<sum+x[q]+x[w]<<endl;
    }
    return 0;
}
