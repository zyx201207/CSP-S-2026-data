#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> s[1000009];
int n,k;
int dep[1000009];
int zy1[1000009];
void dfs11(int t,int fa){
    dep[t]=dep[fa]+1;
    zy1[t]=dep[t];
    for(auto v:s[t]){
        if(v==fa){
            continue;
        }
        dfs11(v,t);
        zy1[t]=max(zy1[t],zy1[v]);
    }
}
int zy2[1000009];
void dfs12(int t,int fa){
    int x,y;
    x=y=0;
    for(auto v:s[t]){
        if(v==fa){
            continue;
        }
        if(zy1[v]-dep[t]>x){
            y=x,x=zy1[v]-dep[t];
        }else if(zy1[v]-dep[t]>y){
            y=zy1[v]-dep[t];
        }
    }
    for(auto v:s[t]){
        if(v==fa){
            continue;
        }
        if(zy1[v]-dep[t]==x){
            zy2[v]=max(y,zy2[t])+1;
        }else{
            zy2[v]=max(x,zy2[t])+1;
        }
        dfs12(v,t);
    }
}
int rt,dd;
bool vis[1000009];
void dfs2(int t,int fa,int x){
    if(zy1[t]==x){
        vis[t]=1;
    }
    for(auto v:s[t]){
        if(v==fa){
            continue;
        }
        dfs2(v,t,x);
    }
}
int dfs3(int t,int fa){
    int g;
    g=0;
    if(vis[t]){
        g=t;
    }
    for(auto v:s[t]){
        if(v==fa){
            continue;
        }
        int p;
        p=dfs3(v,t);
        if(p){
            if(!g){
                g=p;
            }else{
                g=t;
            }
        }
    }
    return g;
}
void dfs4(int t,int fa,int g,bool fl){
    if(vis[t]){
        return;
    }
    if(t==g){
        fl=1;
    }
    if(fl){
        vis[t]=1;
    }
    for(auto v:s[t]){
        if(v==fa){
            continue;
        }
        dfs4(v,t,g,fl);
    }
}
int a[1000009];
int b[1000009];
bool check(int x){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    dfs2(rt,0,x);
    int inn;
    inn=0;
    for(auto v:s[rt]){
        int g;
        g=dfs3(v,rt);
        dfs4(v,rt,g,0);
        if(g){
           ++inn;
            a[inn]=x,b[inn]=g;
        }
    }
    int sum;
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=vis[i];
    }
    if(sum>k){
        return 0;
    }
    return 1;
}
void _main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        s[u].push_back(v),s[v].push_back(u);
    }
    dfs11(1,0);
    zy2[1]=0;
    dfs12(1,0);
    rt=1;
    for(int i=1;i<=n;i++){
        if(max(zy1[i]-dep[i],zy2[i])<max(zy1[rt]-dep[rt],zy2[rt])){
            rt=i;
        }
    }
    dfs11(rt,0);
    zy2[rt]=0;
    dfs12(rt,0);
    dd=0;
    for(int i=1;i<=n;i++){
        dd=max(dd,max(zy1[i]-dep[i],zy2[i]));
        zy1[i]-=dep[i];
        zy2[i]=max(zy2[i],zy1[i]);
    }
    int l,r;
    l=0,r=dd/2;
    while(l<r){
        int mid;
        mid=l+r;
        mid>>=1;
        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
}
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        _main();
    }
    return 0;
}
