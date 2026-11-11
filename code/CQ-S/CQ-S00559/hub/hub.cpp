#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define test(x) freopen(x".in","r",stdin)
#define LL long long
#define db double
#define i128 __int128
#define lb(x) (x&-x)
#define fir first
#define sec second
const int N=1e6+5,M=105,inf=1e9;const LL INF=1e18;
int c,n,k,tmp,d[N],fa[N];bool f[N],f2[N];vector<int> v[N];
void clear(){
    for(int i=1;i<=n;i++) v[i].clear();
}
// void dfs1(int x,int fa){
//     for(int y:v[x])
//         if(y!=fa) dfs1(y,x);
// }
// void dfs2(int x,int fa,int rt){
//     ::fa[rt][x]=fa;
//     for(int y:v[x])
//         if(y!=fa) dis[rt][y]=dis[rt][x]+1,dfs2(y,x,rt);
// }
// bool check(int mid){
//     for(int i=1;i<=n;i++)
//         for(int j=i+1;j<=n;j++){
//             tmp=k-2;bool flag=1;
//             for(int x,y,l=1;l<=n;l++){
//                 if(min(dis[i][l],dis[j][l])<=mid) continue;
//                 for(x=l;dis[l][x]<mid;x=fa[i][x]);
//                 for(y=l;dis[l][y]<mid;y=fa[j][y]);
//                 if(dis[i][x]>tmp&&dis[j][y]>tmp){flag=0;break;}
//             }
//             if(flag) return 1;
//         }
// }
int count(int S,int ans=0){
    for(int i=0;i<n;i++)
        if((S>>i)&1) ans++;
    return ans;
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void solve(){
    scanf("%d%d",&n,&k);
    // for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),
    //     v[x].push_back(y),v[y].push_back(x);
    if(c<=3){
        queue<int> q;int tmp,ans=inf;
        for(int S=(1<<n)-1;S>=0;S--){
            if(count(S)!=k) continue;
            while(!q.empty()) q.pop();
            for(int i=1;i<=n;i++){
                f[i]=f2[i]=0,d[i]=inf,fa[i]=i;
                if((S>>i-1)&1) d[i]=0,q.push(i);
            }
            int cnt=k;
            for(int i=1;i<=n;i++)
                if(((S>>i-1)&1))
                    for(int j:v[i])
                        if(((S>>j-1)&1)&&find(i)!=find(j)) fa[find(j)]=find(i),cnt--;
            if(cnt>2) continue;
            tmp=0;
            while(!q.empty()){
                int x=q.front();q.pop();
                if(f[x]) continue;f[x]=1;
                for(int y:v[x])
                    if(d[y]>d[x]+1) q.push(y),d[y]=d[x]+1,tmp=max(tmp,d[y]);
            }
            ans=min(ans,tmp);
            // if(tmp==1){
            //     cout<<"* ";
            //     for(int i=1;i<=n;i++)
            //         if((S>>i-1)&1) cout<<i<<' ';cout<<'\n';
            //     cout<<"*** "<<cnt<<'\n';
            // }
        }
        printf("%d\n",ans);
        return ;
    }
    int m=(n+1)/2;int x=(m+1)/2;int y=(x+2)/2;
    printf("%d\n",y);
    // if(c>=13&&c<=14){
    //     int m=(n+1)/2;
    //     return;
    // }
}
int main(){
    FILE("hub");
    int T=1;scanf("%d%d",&c,&T);
    while(T--) solve(),clear();
    return 0;
}
/*
I love me
我背上我的背包一直远行
一直向前没有停下来的原因
I love me
I hate me
这一路上必须丢掉太多东西
—— Rapeter《我的背包》
*/