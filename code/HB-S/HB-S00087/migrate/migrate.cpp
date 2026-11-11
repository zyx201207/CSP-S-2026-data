#include<bits/stdc++.h>
#define LL long long

using namespace std;

namespace bf{

const int N=5500;
LL n,d,ans=0,a[N];
pair<int,int>dp[N][N];

void dfs(int u,int stp,int st){
    if(dp[st][u].second>stp){
        dp[st][u].second=stp;
        dp[st][u].first=0;
    }
    if(dp[st][u].second==stp){
        dp[st][u].first++;
    }
    for(int x=u+1;x<=n;x++){
        if(a[u]+d<a[x]){
            break;
        }
        dfs(x,stp+1,st);
    }
}

void solve(){
    cin>>n>>d;
    ans=0;
    for(int x=1;x<=n;x++){
        cin>>a[x];
        for(int y=1;y<=n;y++){
            dp[x][y]={0,1e9};
        }
    }
    for(int x=1;x<=n;x++){
        dfs(x,0,x);
    }
    for(int x=1;x<=n;x++){
        for(int y=x+1;y<=n;y++){
            if(dp[x][y].first==2){
                ans++;
            }
            //cout<<x<<' '<<y<<" "<<dp[x][y].first<<endl;
        }
    }
    cout<<ans<<endl;
}

}

namespace C{
const int N=1e6+500;;
LL n,d,a[N],lt[N],rt[N],ls[N],rs[N],ans=0;

void solve(){
    cin>>n>>d;
    ans=0;
    memset(ls,0,sizeof ls);
    memset(rs,0,sizeof rs);
    memset(lt,0,sizeof lt);
    memset(rt,0,sizeof rt);
    for(int x=1;x<=n;x++){
        cin>>a[x];
    }
    a[0]=a[1]-1;
    a[n+1]=a[n]+1;
    int t=1;
    for(int x=1;x<=n;x++){
        while(a[x]+d>=a[t+1] && t+1<=n+1){
            t++;
        }
        rt[x]=t;
    }
    t=n;
    for(int x=n;x>=1;x--){
        while(a[x]<=a[t-1]+d && t-1>=0){
            t--;
        }
        lt[x]=t;
    }
    for(int x=n-1;x>=1;x--){
        if(a[rt[x]+1]-a[x]>d && rt[x]!=x && lt[rt[x]]==x){
            rs[x]=rs[rt[x]]+1;
        }else{
            rs[x]=0;
        }
    }
    for(int x=2;x<=n;x++){
        if(a[x]-a[lt[x]-1]>d && lt[x]!=x && rt[lt[x]]==x){
            ls[x]=ls[lt[x]]+1;
        }else{
            ls[x]=0;
        }
    }
    for(int x=1;x<=n-1;x++){
        if(a[x]+d>=a[x+1] && rt[x]>x+1 && lt[x+1]<x){
            int L=x+1,R=x;
            LL Lk=0,Rk=0;
            while(1){
                if(lt[rt[R]]!=R){
                    break;
                }
                R=rt[R];
                Rk++;
            }
            while(1){
                if(rt[lt[L]]!=L){
                    break;
                }
                L=lt[L];
                Lk++;
            }
            ans+=Lk*Rk;
       }
    }
    for(int x=1;x<=n;x++){
        //cout<<ls[x]<<" "<<rs[x]<<" "<<lt[x]<<" "<<rt[x]<<endl;
    }
    cout<<ans<<" "<<n*n/2<<endl;
}

}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        bf::solve();
    }
    return 0;
}

/*
#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=5500;
LL n,d,a[N],lt[N],rt[N],ls[N],rs[N],ans=0;
bool is[N][N]={0};

void solve(){
    cin>>n>>d;
    ans=0;
    memset(ls,0,sizeof ls);
    memset(rs,0,sizeof rs);
    memset(lt,0,sizeof lt);
    memset(rt,0,sizeof rt);
    for(int x=1;x<=n;x++){
        cin>>a[x];
    }
    a[0]=a[1]-1;
    a[n+1]=a[n]+1;
    int t=1;
    for(int x=1;x<=n;x++){
        while(a[x]+d>=a[t+1] && t+1<=n+1){
            t++;
        }
        rt[x]=t;
    }
    t=n;
    for(int x=n;x>=1;x--){
        while(a[x]<=a[t-1]+d && t-1>=0){
            t--;
        }
        lt[x]=t;
    }
    for(int x=n-1;x>=1;x--){
        if(a[rt[x]+1]-a[x]>d && rt[x]!=x && lt[rt[x]]==x){
            rs[x]=rs[rt[x]]+1;
        }else{
            rs[x]=0;
        }
    }
    for(int x=2;x<=n;x++){
        if(a[x]-a[lt[x]-1]>d && lt[x]!=x && rt[lt[x]]==x){
            ls[x]=ls[lt[x]]+1;
        }else{
            ls[x]=0;
        }
    }
    for(int x=1;x<=n-1;x++){
        if(a[x]+d>=a[x+1] && rt[x]>x+1 && lt[x+1]<x){
            ans+=rs[x]*ls[x+1];
        }
    }
    for(int x=1;x<=n;x++){
        //cout<<ls[x]<<" "<<rs[x]<<" "<<lt[x]<<" "<<rt[x]<<endl;
    }
    cout<<ans<<" "<<n*n/2<<endl;
}

int main(){
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
*/