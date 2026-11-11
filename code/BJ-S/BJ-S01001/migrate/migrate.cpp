#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long c,t,n,d,x[310],k=0,mi;

void f(long long id,long long en,long long ind){
    if(ind>mi){
        return ;
    }
    if(id==en){
        if(mi>ind){
            mi=ind;
            k=1;
        }else if(mi==ind){
            k++;
        }
        return ;
    }
    for(long long i=id+1;i<=en;i++){
        if(x[id]+d>=x[i]){
            f(i,en,ind+1);
        }else{
            break;
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>x[i];
        }
        long long ans=0;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                mi=1e18;
                k=0;
                f(i,j,0);
                if(k==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
