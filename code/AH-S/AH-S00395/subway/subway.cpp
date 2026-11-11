#include<iostream>
#include<vector>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[5005];
vector<int> g[5005];
vector<int> sub[5005];
int tim[5005][505];
int ans=0x3f3f3f3f3f3f3f3f;
void dfs(int x,int y,int fa,int s,int xian){
    if(x==y){
        ans=min(ans,s);
        return ;
    }
    if(g[x][0]!=fa){
        dfs(g[x][0],y,x,s,xian);
    }else{
        for(int i=1;i<=d;i++){
            if(i==xian) continue;
            if(sub[i][0]==x){
                dfs(sub[i][0],y,x,s+tim[x][xian]+tim[x][i],i);
            }
            if(sub[i][1]==x){
                dfs(sub[i][1],y,x,s+tim[x][xian]+tim[x][i],i);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,x,a1,a2,t1,t2;i<=n;i++){
        cin>>x;
        if(x==2){
            cin>>a1>>t1>>a2>>t2;
            g[a1].push_back(a2);
            g[a2].push_back(a1);
            sub[i].push_back(a1);
            sub[i].push_back(a2);
            tim[a1][i]=t1;
            tim[a2][i]=t2;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;i++){
            if(sub[i].size()!=0&&(sub[i][0]==x||sub[i][1]==x))
                dfs(x,y,-1,w[x],i);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
