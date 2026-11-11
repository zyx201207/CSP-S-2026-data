#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long x[maxn];
int c, t;
long long dif[maxn];
long long tong[maxn];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >>c >>t;
    while(t--){
        long long n, d;
        cin >>n >>d;
        for(int i=1; i<=n; ++i){
            cin >>x[i];
        }
        long long diff=x[2]-x[1];
        bool flag=1;
        for(int i=3; i<=n; ++i){
            if(x[i]-x[i-1]!=diff){
                flag=0;
                break;
            }
        }
        long long cnt=0, cnt2=0;
        long long mul=abs(d/diff);
        for(int i=1; i<=mul; ++i){
            if(n+1-2*i>0) cnt+=n+1-2*i;
        }
        if(n+1-2*mul>0){
            cnt2=n+1-2*mul;
        }else cnt2=0;
        cout <<min(cnt2, cnt) <<"\n";
    }
    return 0;
}