#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int c,t,n,d,x[maxn],dp[maxn],sum[maxn],ans;
vector<int>is[maxn];
int read(){
    int x=0ll,f=1ll;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1ll;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10ll+ch-48ll;ch=getchar();}
    return x*f;
}
bool solve(int u,int v){
    for(int i=1;i<=n;i++)dp[i]=LLONG_MAX-10,sum[i]=0;
    sum[u]=1,dp[u]=0;
    for(int i=u+1;i<=v;i++){
        for(int e:is[i]){
            if(e<u)continue;
            if(dp[i]>dp[e]+1)
                dp[i]=dp[e]+1,sum[i]=1;
            else if(dp[i]==dp[e]+1)++sum[i];
        }
    }
    return sum[v]==2;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    c=read(),t=read();
    while(t--){
        for(int i=1;i<=n;i++)
            is[i].clear();
        ans=0;
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
            for(int j=1;j<i;j++){
                if(x[i]-x[j]<=d)
                    is[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(solve(i,j)){
                    ans++;
                }
        cout<<ans<<'\n';
    }
    return 0;
}
