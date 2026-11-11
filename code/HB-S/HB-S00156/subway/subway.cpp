#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
#define MAXM 500005
int w[MAXM];
struct rp
{
    int a,t;
};
vector<vector<rp>>r;
vector<vector<int>>ww;
int ans;
bool book[MAXM];
int dfs(int p,int e,int now){
    if(p==e){
        return 0;
    }
    int qp=INT_MAX;
    int flag=0;
    book[p]=true;
    for(int i=0;i<ww[p].size();i++){
        int kkk=ww[p][i];
        for(int j=0;j<r[kkk].size();j++){
            if(r[kkk][j].a==p){
                flag==r[kkk][j].t;
            }
            if(book[r[kkk][j].a]!=true){
                int aa=dfs(r[kkk][j].a,e,now+r[kkk][j].t);
                qp=max(qp,aa);
            }
        }
    }
    book[p]==false;
    return ans+qp+flag;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    // cerr<<"OK"<<endl;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            rp rt;
            int a,t;
            scanf("%d%d",&a,&t);
            rt.a=a;
            rt.t=t;
            r[i].push_back(rt);
            ww[a].push_back(i);
        }
    }
    // cerr<<"OK"<<endl;
    for(int i=0;i<q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        ans=0;
        memset(book,0,sizeof(book));
        ans=dfs(u,v,0);
        ans+=w[u]+w[v];
        printf("%d\n",ans);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/