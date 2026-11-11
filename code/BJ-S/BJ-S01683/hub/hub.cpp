#include <bits/stdc++.h>
using namespace std;
int c,T,n,k,x,y;
vector<int> v[1000005];
int maxn[1000005],u,f[1000005],o;
void dfs(int w,int fa,int g){
    maxn[w]=1; int cnt=0,ff=0;
    for(auto p:v[w]) if(p!=fa){
        dfs(p,w,g);
        maxn[w]=max(maxn[p]+1,maxn[w]);
        cnt+=(maxn[p]>g);
        if(maxn[p]>g) ff=p;
        else if(maxn[p]==g) cnt=-433443343;
    }
    if(cnt==1&&fa!=w) f[w]=f[ff]+1,u=max(u,f[w]);
    else f[w]=0;
    if(maxn[w]>g) ++o;
}
bool check(int g){
    int ans=0x3f3f3f3f; int O=(10000000)/(n*__lg(n));
    for(int oo=1;oo<=O&&oo<=n;oo++){
        int i=oo;
        u=0; o=0;
        dfs(i,i,g);
        ans=min(ans,o-min(u,g*2));
    }
    return ans<=k;
}
bool vis[15];
int dis[15];
void dfs(int w,int g){
    vis[w]=1;
    for(auto p:v[w]) if(!vis[p]&&((1<<p-1)&g)) dfs(p,g);
}
int main(){freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T); srand(time(0));
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(c==13||c==14){
            int m=n/2;
            if(k==1) printf("%d\n",m/2+1);
            else if(k<m) printf("%d\n",(m+1-(k-3))/4+1);
            else if(k>=n) printf("0\n");
            else printf("1\n");
            continue;
        }

        if(c<=3&&c>=1){
        int ans=0x3f3f3f3f;
        for(int i=1;i<(1<<n);i++){
            for(int j=1;j<=n;j++) vis[j]=0,dis[j]=0x3f3f3f3f; int cnt=0;
            for(int j=1;j<=n;j++) if((1<<j-1)&i) if(!vis[j]){
                dfs(j,i);
                cnt++;
            }
            if(cnt<=2){
                queue<int> q;
                for(int j=1;j<=n;j++) if((1<<j-1)&i) q.push(j),dis[j]=0;
                if(q.size()<=k){int f=0;
                    while(!q.empty()){
                        int h=q.front(); q.pop();
                        f=max(f,dis[h]);
                        for(auto p:v[h]) if(dis[p]>dis[h]+1){
                            dis[p]=dis[h]+1;
                            q.push(p);
                        }
                    }ans=min(ans,f);
                }
            }
        }printf("%d\n",ans);
        }else{
        int l=0,r=n,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    }
    return 0;
}


