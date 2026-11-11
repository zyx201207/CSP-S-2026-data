#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
bool vis[1000005];
int fa[1000005];
int dep[1000005];
int st[1000005][22];
vector<int> v[1000005];
long long ans=1e18,maxn=0,minn=1e18;
void dfs1(int x,int f){
    dep[x]=dep[f]+1;
    st[x][0]=f;
    for(int i=1;i<=20;i++)
    st[x][i]=st[st[x][i-1]][i-1];
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(y==f)continue;
        dfs1(y,x);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[st[x][i]]>=dep[y])
        x=st[x][i];
    }
    if(x==y)return y;
    for(int i=20;i>=0;i--){
        if(st[x][i]!=st[y][i])
        x=st[x][i],y=st[y][i];
    }
    return st[x][0];
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void dfs2(int now,int num){
    if(num==k){
        for(int i=1;i<=n;i++){
            if(vis[i]==0)continue;
            for(int j=0;j<v[i].size();j++){
                if(vis[v[i][j]]==0)continue;
                int fx=find(i);
                int fy=find(v[i][j]);
                if(fx!=fy)fa[fx]=fy;
            }
        }
        bool flag=1;
        int p1=0,p2=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0)continue;
            if(p1==0)p1=find(i);
            else if(p1!=0&&find(i)!=p1&&p2==0)p2=find(i);
            else if(p1!=0&&find(i)!=p1&&p2!=0&&find(i)!=p2)flag=0;
        }
        for(int i=1;i<=n;i++)
        fa[i]=i;
        if(flag==0)
        return;
        /*for(int i=1;i<=n;i++){
            if(vis[i]==1)cout<<i<<" ";
        }
        cout<<endl;*/
        maxn=0;
        for(int i=1;i<=n;i++){
            minn=1e18;
            for(int j=1;j<=n;j++){
                if(vis[j]==0)continue;
                int m=lca(i,j);
                minn=min(minn,0ll+dep[i]-dep[m]+dep[j]-dep[m]);
            }
            maxn=max(maxn,minn);
        }
        ans=min(ans,maxn);
        return;
    }
    if(now>n)return;
    vis[now]=1;
    dfs2(now+1,num+1);
    vis[now]=0;
    dfs2(now+1,num);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        ans=1e18;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            fa[i]=i;
            dep[i]=0;
            for(int j=0;j<=20;j++)
            st[i][j]=0;
            v[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs1(1,0);
        dfs2(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
