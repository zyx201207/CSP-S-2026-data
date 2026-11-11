#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,c,t,q,h,bz,d;
    long long x[2000005];
    long long cha[200005];
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        bz=1;
        cin>>n>>d;
        for(long long j=1;j<=n;j++){
            cin>>x[j];
            if(j>=2){
                q=x[bz];
                h=x[j];
                cha[bz]=h-q;
            }
        }

    }
    for(int i=1;i<=t;i++){
            cout<<i<<endl;
    }
}
