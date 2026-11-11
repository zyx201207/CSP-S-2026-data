#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1000005];
int f[1000005];
int is[1000005];
int gen[1005][10];
int find(int x){
    if(x==f[x]){
        return x;
    }
    return f[x]=find(f[x]);
}
int merge(int x,int y){
    f[find(x)]=find(y);
}
int dep[1000005];
int eee=0;
int dfs(int x,int fa){
    eee++;
    if(eee==6){
        exit(0);
    }
    for(int i=0;i<v[x].size();i++){
        int p=v[x][i];
        if(p!=fa){
            dep[p]=dep[x]+1;
            gen[p][0]=x;
            dfs(p,x);
        }
    }
}
int lca(int x,int y){
    if(dep[x]>dep[y]){
        swap(x,y);
    }
    for(int i=10;i>=1;i--){
        int ty=gen[y][i];
        if(dep[ty]>=dep[x]){
            y=ty;
        }
    }
    if(x==y){
        return x;
    }
    for(int i=10;i>=1;i--){
        int tx=gen[x][i];
        int ty=gen[y][i];
        if(tx!=ty){
            x=tx,y=ty;
        }
    }
    return gen[x][0];
}
int lg(int x,int y){
    int ll=lca(x,y);
    return dep[x]+dep[y]-2*dep[ll];
}
int main(){
    ios::sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,-1);
        exit(0);
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                gen[i][j]=gen[gen[i][j-1]][j-1];
            }
        }
        int tar=1<<n;
        int minn=1e9;
        for(int i=0;i<tar;i++){
            for(int j=1;j<=n;j++){
                is[j]=0;
                f[j]=i;
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    cnt++;
                    is[j+1]=1;
                }
            }
            if(cnt!=k){
                continue;
            }
            for(int j=1;j<=n;j++){
                if(is[j]){
                    for(int l=0;l<v[j].size();l++){
                        int p=v[j][l];
                        if(is[p]){
                            merge(p,j);
                        }
                    }
                }
            }
            cnt=0;
            for(int i=1;i<=n;i++){
                if(i==find(i)){
                    cnt++;
                }
            }
            if(cnt>2){
                continue;
            }
            int maxn=0;
            for(int i=1;i<=n;i++){
                int cur=1e9;
                for(int j=1;j<=n;j++){
                    if(is[j]){
                        cur=min(cur,lg(i,j));
                    }
                }
                maxn=max(maxn,cur);
            }
            minn=min(minn,maxn);
        }
        cout<<minn<<'\n';
    }
    return 0;
}
//Arsenal was and still is my love.
//North London Forever.
