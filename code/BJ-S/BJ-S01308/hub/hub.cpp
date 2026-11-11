#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,t,n,k;
vector<int> v[N];
int tt[N];
int vis[N];
int ans=0;
void dfss(int x,int fa){
    vis[x]=1;
    for(auto y:v[x]){
        if(!tt[y]||y==fa)continue;
        dfss(y,x);
    }
}
int dfsss(int x,int f){
    if(tt[x])return 0;
    int num=0x3f3f3f3f;
    for(auto y:v[x]){
        if(y==f)continue;
        num=min(num,dfsss(y,x)+1);
    }
    return num;
}
int check(){
    int num=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++){
        if(tt[i]==1&&vis[i]==0){
            num++;
            dfss(i,i);
        }
    }
    if(num>2)return 0x3f3f3f3f;
    num=0;
    for(int i=1;i<=n;i++){
        num=max(num,dfsss(i,i));
    }
    return num;
}
void dfs(int x,int num){
    if(num==k){
        ans=min(ans,check());
        return;
    }
    if(x==n+1)return;
    tt[x]=1;
    dfs(x+1,num+1);
    tt[x]=0;
    dfs(x+1,num);
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0x3f3f3f3f;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(c==13||c==14){
            if(k>1)ans=(((n-1)/2-k+2)/3)+1;
            else ans=((n-1)/2-k+1)/2+1;
        }else dfs(1,0);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}