#include<bits/stdc++.h>
using namespace std;
const int NR=2e6+5;
int C,T;
int n;
long long d,a[NR];
int f[NR];
long long g[NR];
void solve(){
    scanf("%d %lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        f[i]=0,g[i]=1;
        long long sum=1;
        int last=1;
        deque<int> q;
        q.push_back(i);
        for(int j=i+1;j<=n;j++){
            while(!q.empty()&&a[j]-a[q.front()]>d){
                sum-=g[q.front()];
                q.pop_front();
            }
            if(q.empty()) break;
            if(f[q.front()]+1!=last){
                sum=g[q[0]];
                last=f[q.front()]+1;
                for(int k=1;k<q.size();k++){
                    if(f[q[k]]==f[q[0]]) sum+=g[q[k]];
                    else break;
                }
            }
            f[j]=last,g[j]=sum;
            if(g[j]==2) ans++;
            q.push_back(j);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&C,&T);
    while(T--){
        solve();
    }
    return 0;
}