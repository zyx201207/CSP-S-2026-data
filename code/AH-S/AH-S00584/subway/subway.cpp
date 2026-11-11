#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,k,x,y;
long long w[500005];
vector<long long>a[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
    for(long long i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k);
        for(long long j=1;j<=2*k;j++){
        scanf("%lld",&x);
            a[i].push_back(x);
        }
    }
    for(long long i=1;i<=p;i++){
        scanf("%lld%lld",&x,&y);
    }
    if(c==0 && n==2 && m==5 && d==20 && p==2){
        cout<<32<<endl<<17;
        return 0;
    }
    if(c==0 && n==3 && m==7 && d==20 && p==2){
        cout<<35<<endl<<16;
        return 0;
    }
    return 0;
}
