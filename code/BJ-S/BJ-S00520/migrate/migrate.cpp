#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
long long n,d;
long long ans  = 0;
long long minn = 0x3f3f3f3f3f3f3f3fll;
void dfs(long long pos, long long cnt, long long ed){
    if(pos == ed){
        if(cnt < minn){
            minn = cnt;
            ans = 1;
        }else if(cnt == minn){
            ans++;
        }
    }
    for(long long i = pos+1;i <= n;i++){
        if(x[i]-x[pos] > d){
            break;
        }else{
            dfs(i,cnt+1,ed);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    long long c,T;
    cin>>c>>T;
    while(T--){
        long long isA = 1;
        cin>>n>>d;
        for(long long i = 1; i <= n; i++){
            cin>>x[i];
            if(i >= 2){
                if(x[i]-x[i-1] != x[i-1]-x[i-2]) isA = 0;
            }
        }
        if(isA){
            long long c = x[2]-x[1];
            if(2*d < c){
                cout<<0<<endl;
            }else{
                cout<<n-2*(d/c)+1<<endl;
            }
            continue;
        }
        long long res = 0;
        for(long long i = 1; i <= n; i++){
            for(long long j = i+1; j <= n; j++){
                minn = 0x3f3f3f3f3f3f3f3fll;
                ans = 0;
                dfs(i,0,j);
                if(ans == 2){
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
}
