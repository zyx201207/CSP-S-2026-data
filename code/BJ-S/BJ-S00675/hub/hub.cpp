#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int n=0,f=1;
    char c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    return n*f;
}

inline void write(int x){
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x>9)write(x/10);
    putchar(x%10^48);
    return;
}

int n,k,ans;
int dp[1000005];
vector<int>v[1000005];
pair<int,int>ban;

pair<int,int>far(int x,int fa){
    int mx=0;
    int id=x;
    for(auto y:v[x]){
        if(y==fa)continue;
        if(make_pair(y,x)==ban||make_pair(x,y)==ban)continue;
        auto [f,s]=far(y,x);
        if(s+1>mx){
            mx=s+1;
            id=f;
        }
    }
    return{id,mx};
}

pair<int,int>find_cut(int x,int fa,int len,int t,int de=1){
    for(auto y:v[x]){
        if(y==fa)continue;
        if(make_pair(y,x)==ban||make_pair(x,y)==ban)continue;
        auto [f,s]=find_cut(y,x,len,t,de+1);
        if(f==0&&s==0)continue;
        if(f!=0&&s==0){
            if(len==de){
                return {x,y};
            }
            else return {f,s};
        }
        if(f!=0&&s!=0)return {f,s};
    }
    if(x==t)return {x,0};
    return {0,0};
}

void dfs(int x,int fa){
    for(auto y:v[x]){
        if(y==fa)continue;
        if(make_pair(y,x)==ban||make_pair(x,y)==ban)continue;
        dfs(y,x);
        dp[x]=max(dp[x],dp[y]);
    }
    ++dp[x];
    return;
}

int check(){
    int vl=ban.first;
    int vr=ban.second;
    int ul=far(vl,0).first;
    int ur=far(vr,0).first;
    int fl,fr;
    tie(vl,fl)=far(ul,0);++fl;
    tie(vr,fr)=far(ur,0);++fr;
    int Ol=find_cut(ul,0,(fl+1)/2,vl).first;
    int Or=find_cut(ur,0,(fr+1)/2,vr).first;
    dfs(Ol,0);
    dfs(Or,0);
    //cout<<ul<<" "<<vl<<" "<<fl<<"\n";
    //cout<<ur<<" "<<vr<<" "<<fr<<"\n";
    //cout<<Ol<<" "<<Or<<"\n";
    priority_queue<int>pq;
    pq.push(0);
    for(int i=1;i<=n;++i){
        if(i!=Ol&&i!=Or)pq.push(dp[i]);
    }
    int cnt=k-2;
    while(cnt--){
        pq.pop();
    }
    return pq.top();
}

signed mian(){
    for(int i=1;i<=n;++i)v[i].clear();
    memset(dp,0,sizeof dp);
    ban={0,0};
    n=read();
    k=read();
    for(int i=1;i<n;++i){
        int x=read();
        int y=read();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int u=far(1,0).first;
    auto [V,zj]=far(u,0);++zj;
    ban=find_cut(u,0,zj/2,V);
    //cout<<zj<<"\n";
    //cout<<ban.first<<" "<<ban.second<<":\n";
    ans=check();
    if(zj%2==1){
        ban={0,0};
        ban=find_cut(u,0,zj/2+1,V);
        //cout<<ban.first<<" "<<ban.second<<":\n";
        ans=min(check(),ans);
    }
    write(ans);
    putchar('\n');
    return 0;
}

signed main(){
    //freopen("hub.in","r",stdin);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),t=read();
    while(t--){
        mian();
    }
    return 0;
}