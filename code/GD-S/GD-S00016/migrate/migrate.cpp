#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x=0,fl=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fl=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10ll+ch-'0';
        ch=getchar();
    }
    return x*fl;
}
void write(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
ll n,d,a[2000001],ans,dis[2000001],cnt[2000001];
vector<int>e[2000001];
void solve(int s){
    queue<int>q;
    for(int i=1;i<=n;i++)dis[i]=n+1,cnt[i]=0;
    dis[s]=0,cnt[s]=1;
    q.push(s);
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        for(auto v:e[fr]){
            if(dis[fr]+1<dis[v]){
                dis[v]=dis[fr]+1;
                cnt[v]=cnt[fr];
                q.push(v);
            }else if(dis[fr]+1==dis[v]){
                cnt[v]+=cnt[fr];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==2)ans++;
    }
}
void mian(){
    ans=0;
    n=read(),d=read();
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        e[i].clear();
        for(int j=1;j<=n;j++){
            if(abs(a[i]-a[j])<=d)e[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++)solve(i);
    cout<<ans/2<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int testid=read(),t=read();
    while(t--)mian();
    return 0;
}