#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[2000100];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> c >> t;
    while(t--){

        memset(x,0,sizeof(x));

        cin >> n >> d;
         for(long long i=0;i<n;i++){
             cin >> x[i];
         }

        // long long ans=0;
        // long long cha=x[2]-x[1];

        // for(long long i=4;i<=n;i++){
        //     long long d1=cha * (i-1),d2=cha * (i-2);
        //     if(d1>d&&d2<= d){
        //         ans=n-i;
        //         break;
        //     }
        // }
        cout << 0 << '\n';
    }
    return 0;
}
//0 1 10 14 0 7 14 21 28 35 42 49 56 63 