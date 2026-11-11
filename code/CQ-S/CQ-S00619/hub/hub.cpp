#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rd(){int x=0,fh=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') fh=-1;ch=getchar();}while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*fh;}
const int N=1e6+10;
int n,k,x,y,dep[N],fa[N];
vector<int> g[N],p;
bool vis[N];

void dfs1(int u,int f,int &rt){
    dep[u]=dep[f]+1,fa[u]=f;
    if(dep[u]>dep[rt]) rt=u;
    for(int v:g[u]){
        if(v==f) continue;
        dfs1(v,u,rt);
    }
}

int Dep[N],mxdep[N],D;

void dfs2(int u,int f,int &ans){
    Dep[u]=Dep[f]+1,mxdep[u]=Dep[u];
    for(int v:g[u]){
        if(vis[v]||v==f) continue;
        dfs2(v,u,ans);
        mxdep[u]=max(mxdep[u],mxdep[v]);
    }
    if(!vis[u]&&mxdep[u]-Dep[u]>=D) ans++;
}

bool ck(int d){
    D=d;
    int ans=2;
    int L=d,R=(int)p.size()-1-d;
    vector<int> b;
    b.push_back(L);
    for(int i=L+1;i<R;i++){
        dfs2(p[i],0,ans);
        if(mxdep[p[i]]>=d) b.push_back(i);
    }
    b.push_back(R);
    int TMP=ans;
    ans=k+1;
    for(int i=1;i<(int)b.size();i++){
        int res=TMP+(R-L-1)-(b[i]-b[i-1]-1);
        vector<pair<int,int> > pr;
        for(int j=b[i-1]+1;j<b[i];j++){
            int ned=max(0,d-mxdep[p[j]]);
            if(b[i-1]<j-ned&&j+ned<b[i]){
                pr.push_back({j-ned,j+ned});
            }
        }
        int tmp=n+1;
        if(pr.empty()){
            tmp=0;
        }
        else{
            sort(pr.begin(),pr.end());
            for(int j=(int)pr.size()-2;j>=0;j--){
                pr[j].second=min(pr[j].second,pr[j+1].second);
            }
            tmp=b[i]-pr[0].second;
            for(int j=0,k=0;j<(int)pr.size();j++){
                while(k<(int)pr.size()&&pr[j].first>=pr[k].first) k++;
                tmp=min(tmp,pr[j].first-b[i-1]+(k<(int)pr.size()?b[i]-pr[k].second:0));
            }
        }
        res+=tmp;
        ans=min(ans,res);
    }
    return ans<=k;
}

void solve(){
    n=rd(),k=rd();
    for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
    for(int i=1,u,v;i<n;i++){
        u=rd(),v=rd();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==k) return puts("0"),void();
    x=0,y=0;
    dfs1(1,0,x),dfs1(x,0,y);
    int L=dep[y],u=y;
    p.clear();
    while(u) p.push_back(u),vis[u]=1,u=fa[u];
    reverse(p.begin(),p.end());
    int l=0,r=L/2;
    while(l<=r){
        int mid=l+r>>1;
        if(ck(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
}

int main(){
    dep[0]=Dep[0]=-1;
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    rd();int t=rd();
    while(t--) solve();
    return 0;
}