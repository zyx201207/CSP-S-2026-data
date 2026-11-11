#include <bits/stdc++.h>

using namespace std;
const long long N=2*1e6;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--){
        long long n,d;
        cin >> n >> d;
        long long a[N];
        bool flag=false;
        for(long long i=1;i<=n;i++){
            cin >> a[i];
        }
        if(d%2==1){
            cout<<0<<endl;
            continue;
        }
        long long cnt=0;
        for(long long i=2;i<=4;i++){
            if(a[i]-a[i-1]!=d/2){
                flag=true;
                break;
            }
        }
        if(!flag){
            cnt++;
        }
        flag=false;
        for(long long i=2;i+4-1<=n;i++){
            long long j=i+4-1;
            flag=false;
            for(long long k=i+1;k<=j;k++){
                if(a[k]-a[k-1]!=d/2){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
