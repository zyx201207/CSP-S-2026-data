#include<bits/stdc++.h>
using namespace std;
long long dp[200005][33],a[200005];
long long n,m;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        long long b=a[i],cnt=0;
        while(b){
            dp[a[i]][cnt++]=b%2;
            b/=2;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=30;i>=0;i--){
        long long cnt=0;
        vector<long long> q;
        for(long long j=1;j<=n;j++){
           if(dp[a[j]][i]){
                cnt++;
                q.push_back(a[j]);
                if(q.size()-1==m){
                    break;
                }
           }
        }
        if(q.size()==m){
                long long cmd=q[0];
            for(int i=1;i<q.size();i++){
                cmd&=q[i];
            }
            cout<<cmd;
            return 0;
        }

    }

    cout<<0;
    return 0;
}
