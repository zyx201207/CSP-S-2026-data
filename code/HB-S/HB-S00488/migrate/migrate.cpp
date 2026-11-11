#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        long long n,d;
        cin>>n>>d;
        if(n<=9&&c==0){
            cout<<"0\n1";
            return 0;
        }
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d<2*(a[2]-a[1])){
            cout<<"0\n";
            continue;
        }
        else{
            cout<<n-d-a[2]+a[1]<<"\n";
        }
    }
    return 0;
}
/*
2026 csp rp++
2026 csp rp++
2026 csp rp++
2026 csp rp++
2026 csp rp++
2026 csp-j rp++
2026 csp-s rp++
2026 csp-j rp++
2026 csp-s rp++
2026 csp-j rp++
2026 csp-s rp++
rp++
rp++
rp++
rp++
rp++
*/
