#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=2e6+20;
long long x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t){
        int n;
        long long d,cnt=0;
        cin>>n>>d;
        if(n<4){
            cout<<0<<endl;
            break;
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long q=x[2]-x[1];
        if(2*q>d){
            cout<<0<<endl;
            break;
        }
        for(int i=4;i<=n;i+=2){
            long long l=i-1;
            if(x[i]+d>=x[i]) continue;
            if(x[1]+2*d<=x[i]) continue;
            else{
                cnt+=n-l;
            }
        }

        cout<<cnt<<endl;
        for(int i=1;i<=n;i++){
            x[i] = 0;
        }

    }

    return 0;
}
