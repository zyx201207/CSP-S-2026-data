#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=1000005;
int cid,T,n,k,fa[maxn],dit[maxn],dit2[maxn],dig[maxn],son[maxn],top[maxn],dy[maxn],dy_[maxn],dep[maxn];
int dp1[maxn],dp2[maxn],dp3[maxn],dp_[maxn],nw[maxn],nw_[maxn],tg[maxn];
vector<int> tree[maxn],vg[maxn];
vector<pair<int,int>> stk[maxn],stk_[maxn],kc[maxn];
void dfs(int s){
    dit[s]=0;dit2[s]=0;son[s]=0;top[s]=s;
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j];
        if(s_==fa[s])continue;
        fa[s_]=s;
        dep[s_]=dep[s]+1;
        dfs(s_);
        if(dit[s_]+1>dit[s])son[s]=s_,dit2[s]=dit[s],dit[s]=dit[s_]+1,top[s]=top[s_];
        else dit2[s]=max(dit2[s],dit[s_]+1);
    }
    vg[top[s]].push_back(s);
}
void dfsr(int s){
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j];
        if(s_==fa[s])continue;
        if(s_==son[s])dig[s_]=1+max(dig[s],dit2[s]);
        else dig[s_]=1+max(dig[s],dit[s]);
        dfsr(s_);
    }
}
bool dfs_(int s,int L){
    dp1[s]=1;
    dp3[s]=1;
    int add=0;
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j];
        if(s_==fa[s])continue;
        if(dfs_(s_,L))return true;
        if(dit[s_]>=L){
            dp1[s]+=dp1[s_];
            dp3[s]+=dp1[s_];
            int ks=0;
            if(dit[s_]<L)ks=0;
            else ks=min(dp3[s_],dp_[s_]);
            add=min(add,ks-dp1[s_]);
        }
    }
    dp3[s]+=add;
    if((dp1[s]<=k||dp3[s]<=k)&&dig[s]<=L)return true;
    int t=top[s];
    pair<int,int> tmp=make_pair(dy[s],dp1[s]);
    while(nw[t]<stk[t].size()&&stk[t].back().second>=tmp.second)stk[t].pop_back();
    stk[t].push_back(tmp);
    while(nw[t]<stk[t].size()&&stk[t][nw[t]].first<dit[s])nw[t]++;
    dp2[s]=stk[t][nw[t]].second;
    tmp=make_pair(dy_[s],dp2[s]);
    while(nw_[t]<stk_[t].size()&&stk_[t].back().second>=tmp.second)stk_[t].pop_back();
    stk_[t].push_back(tmp);
    while(nw_[t]<stk_[t].size()&&stk_[t][nw_[t]].first<dit[s])nw_[t]++;
    dp_[s]=stk_[t][nw_[t]].second;
    //printf("%d %d %d %d\n",s,dp1[s],dp2[s],dp3[s]);
    return false;
}
void dfs__(int s,int L,pair<int,int> r1,pair<int,int> r2){
    if(dep[s]>L)return;
    if(dep[s]>r1.first&&dep[s]<=r2.first){
        kc[r1.second].push_back(make_pair(L-(dep[s]-dep[r1.second]+1)-1,dp1[s]));
    }
    pair<int,int> pg[3];
    for(int i=0;i<=2;++i)pg[i]=make_pair(n+1,0);
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j];
        if(s_==fa[s])continue;
        pair<int,int> t=make_pair(L+dep[s_]-dit[s_]-1,s_);
        if(pg[2]>t)swap(pg[2],t);
        if(pg[1]>pg[2])swap(pg[1],pg[2]);
        if(pg[0]>pg[1])swap(pg[0],pg[1]);
    }
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j];
        if(s_==fa[s])continue;
        pair<int,int> v[4]={r1,r2};
        int cnt=2;
        for(int i=0;i<=2&&cnt<4;++i){
            if(pg[i].second!=s_)v[cnt++]=pg[i];
        }
        sort(v,v+4);
        dfs__(s_,L,v[0],v[1]);
    }
}
bool check(int L){
    for(int i=1;i<=n;++i)if(vg[i].size()){
        stk[i].clear();nw[i]=0;
        stk_[i].clear();nw_[i]=0;
        for(int j=0,u=0;j<vg[i].size();++j){
            while(u+1<vg[i].size()&&u+1-j+dit2[vg[i][u+1]]<=L||u+1==j)++u;
            dy[vg[i][j]]=u;
        }
        int nt=n+1;
        for(int j=vg[i].size()-1;j>=0;--j){
            dy_[vg[i][j]]=nt;
            if(dit2[vg[i][j]]>=L)nt=min(nt,j-1);
            else nt=min(nt,j+L-1-dit2[vg[i][j]]);
        }
    }
    for(int i=1;i<=n;++i)kc[i].clear();
    if(dfs_(1,L))return true;
    dfs__(1,L,make_pair(n+1,0),make_pair(n+1,0));
    for(int i=1;i<=n;++i)if(vg[i].size()){
        for(int j=0;j<vg[i].size();++j){
            int x=vg[i][j];
            tg[j]=j-1;
            for(int u=j;u>j-dit2[x];--u)tg[u]=j;
            for(int u=0;u<kc[x].size();++u){
                int y=kc[x][u].first,bas=kc[x][u].second;
                if(y<0){
                    if(bas+dp2[x]<=k)return true;
                    continue;
                }
                y=tg[j-y];
                if(bas+dp2[vg[i][y]]<=k)return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>cid>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;++i)tree[i].clear();
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        for(int i=1;i<=n;++i)vg[i].clear();
        dfs(1);
        dfsr(1);
        int L=0,R=n;
        //check(0);return 0;
        while(L<R){
            int mid=L+R>>1;
            if(check(mid))R=mid;
            else L=mid+1;
        }
        cout<<L<<'\n';
    }
    return 0;
}