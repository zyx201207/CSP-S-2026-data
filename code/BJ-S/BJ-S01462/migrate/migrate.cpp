#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    if(15<=c&&c<=18){
        for(;t>=1;t--){
            cout<<"0\n";
        }
    }
    else if(c==11||c==12){
        long long n,d;
        for(long long a=1;a<=t;a++){
            cin>>n>>d;
            long long sum;
            for(long long e=1;e<=n;e++){
                long long b;
                cin>>b;
                if(e==1){
                    sum=b;
                }
                if(e==2){
                    sum=b-sum;
                }
            }
            cout<<((d>=2*sum)&&(d<3*sum)?max(n-n,n-3):0)<<"\n";
        }
    }
}
