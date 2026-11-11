#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,wayid,T;
long long w[500005];
long long c12[500005],ans[500005];
struct node{
    int v;
    int line;
};
vector <node> e[500005];
void dfs(int u,int fa,int id,int tot){
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i].v;
        if(v==fa||v==0) continue;
        int line=e[u][i].line;
        int leftline=e[fa][id].line;
        if(fa==u){
           leftline=e[u][i].line;
        }
        if(leftline!=line){
            tot+=1;
        }
        if(ans[v]>tot){
            ans[v]=tot;
            dfs(v,u,i,tot);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>c12[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        wayid++;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>w[j]>>T;
            e[w[j-1]].push_back(node{w[j],wayid});
            e[w[j]].push_back(node{w[j-1],wayid});
        }
    }
    for(int i=1;i<=q;i++){
        memset(ans,0x3f,sizeof(ans));
        int l,r;
        cin>>l>>r;
        ans[l]=0;
        dfs(l,l,0,0);
        cout<<(ans[r]*2+2)*T+c12[l]+c12[r]<<endl;
    }

    return 0;
}

