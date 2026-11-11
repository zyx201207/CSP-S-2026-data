#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c = 0;
    long long t = 0;
    cin>>c>>t;
    long long cnt = 0;
    for(int k = 1; k <= t; k++){
        long long n,d;
        cnt = 0;
        long long x[n + 1];
        cin>>n>>d;
        for(long long i = 1; i <= n; i++){
            cin>>x[i];
        }
        for(long long j = 1; j <= n; j++){
            for(long long i = j + d + 1; i <= n; i++){
                if(x[i] - x[j] - d == d - 1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
