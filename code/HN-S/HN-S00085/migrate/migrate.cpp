#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 2e6+5;
LL caseid,T,n,d,a[N];
LL read(){
    LL su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}
namespace sub1{
    const int maxn = 5005;
    const int INF = 1e9+1099;
    bool flag[maxn][maxn],vis[maxn];
    int dis[maxn],cnt[maxn],ans;
    void main(){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)flag[i][j]=0;
        ans=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[j]-a[i]<=d)flag[i][j]=1;
        for(int st=1;st<n;st++){
            queue<int> q;
            while(!q.empty())q.pop();
            for(int i=st;i<=n;i++)dis[i]=INF,cnt[i]=0,vis[i]=0;
            q.push(st);dis[st]=0,cnt[st]=1,vis[st]=1;
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int v=u+1;v<=n&&flag[u][v];v++)
                    if(!vis[v]&&dis[u]+1<dis[v])
                        dis[v]=dis[u]+1,vis[v]=1,cnt[v]=cnt[u],q.push(v);
                    else if(dis[u]+1==dis[v])cnt[v]+=cnt[u];
            }
            for(int i=st+1;i<=n;i++)if(cnt[i]==2)ans++;
        }
        cout<<ans<<"\n";
        return;
    }
}
namespace sub2{
    int ans;
    void main(){
        ans=0;
        LL cha=a[2]-a[1];
        LL cnt=min(n-1,d/cha);
        for(int st=1;st<n;st++)
            if(st+cnt+cnt-1<=n&&st+cnt+cnt-1>st+1)ans++;
        cout<<ans<<"\n";
        return;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    caseid=read(),T=read();
    while(T--){
        n=read(),d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        if(caseid<=10)sub1::main();
        else if(caseid>=11&&caseid<=12)sub2::main();
    }
    return 0;
}
//rp++
//到底是什么 让一切变了样 ——《谁听》
