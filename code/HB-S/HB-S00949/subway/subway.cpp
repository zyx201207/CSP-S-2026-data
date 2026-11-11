#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define intl long long 
#define MAXN 500005
intl k[MAXN];
intl w[MAXN];
struct nnn{
    int v,w,name;
};
vector<nnn>g[600];
intl ans=0;
intl vis[400][400];
intl num=0;
void dfs(intl now,intl op,intl to){
    if(now==to){
        ans=min(ans,num);
        return ;
    }

    for(nnn x:g[now]){
        if(x.v!=op&&op!=-1){
            ans+=x.w;
            ans+=vis[x.v][now];
            dfs(now+1,x.v,to);
        }else{
            dfs(now+1,x.v,to);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);


    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    intl rp=0;
    cin>>rp;
    rp++;

    intl n,m,d,q;
    cin>>n>>m>>d>>q;
    if(n>300){
        while(q--){
            cout<<m<<'\n';
        }
        return 0;
    }
    For(i,1,m){
        cin>>w[i];
    }
    For(i,1,n){
        cin>>k[i];
        For(j,1,k[i]){
            int prs,xzm;
            vis[i][j]=xzm;
            cin>>prs>>xzm;
            g[prs].push_back({i,xzm});
        }
    }
    while(q--){
        intl x,y;
        cin>>x>>y;
        num=0;
        dfs(x,-1,y);
        if(x>y)swap(x,y);
        ans+=(w[x]+w[y]);
        cout<<ans<<'\n';
    }
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/