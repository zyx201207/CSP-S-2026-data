//毕节七星关东辰实验学校 刘杰 GZ-S00073
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MX=1e6+10;

int n,k;vector<int> ed[MX];
vector<int> li[MX];
bool o[MX];

void dfs(int u,int fa){
    o[u]=1;
    for(int i=0;i<li[u].size();i++){
        if(li[u][i]!=fa){
            dfs(li[u][i],u);
        }
    }
}

bool ck(unsigned int pp){
    memset(o,0,sizeof(o));
    for(int i=1;i<=n;i++){
        li[i].clear();
    }
    int ct=0;
    for(int i=1;i<=n;i++){
        if(((pp>>(i-1))&1)==1){
            for(int j=0;j<ed[i].size();j++){
                if(((pp>>(ed[i][j]-1)&1))==1){
                    li[i].push_back(ed[i][j]);
                }
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(((pp>>i)&1)==1){
            ct++;
        }
    }
    //cout<<ct<<endl;
    if(ct!=k)    return 0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!o[i]&&((pp>>(i-1))&1)){
            dfs(i,0);ans++;
        }
    }
    if(ans==2)    return 1;
    return 0;
}

int dis[MX];

void dfs2(int u,int fa,int pl){
    dis[u]=min(dis[u],pl);
    for(int i=0;i<ed[u].size();i++){
        if(ed[u][i]!=fa){
            dfs2(ed[u][i],u,pl+1);
        }
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        ed[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    int ans=LLONG_MAX;
    for(unsigned int p=0;p<(1ull<<(n));p++){
            //cout<<p<<endl;
        if(ck(p)){
            //cout<<"---CHeck"<<p<<"---"<<endl;
            memset(dis,0x3f,sizeof(dis));
            for(int i=1;i<=n;i++){
                if((p>>(i-1))&1){
                    dis[i]=0;
                    dfs2(i,0,0);/*
        for(int j=1;j<=n;j++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;*/
                }
            }
            int up=LLONG_MIN;
            for(int i=1;i<=n;i++){
                if(dis[i]!=0)
                    up=max(dis[i],up);
            }
            //cout<<up<<endl<<endl;
            ans=min(ans,up);
        }
    }
    cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
        solve();
	}
}
