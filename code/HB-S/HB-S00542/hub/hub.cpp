#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,f[105];
bool book[105];
inline int getf(int x){return (f[x]==x)?x:f[x]=getf(f[x]);}
inline void merge(int x,int y){
    int fx=getf(x),fy=getf(y);
    if(fx!=fy)f[fx]=fy;
}
vector<int> e[1000005];
int dfs(int x,int fa,int dep=0){
    if(book[x])return dep;
    int minn=INT_MAX;
    for(auto i:e[x])if(i!=fa)minn=min(minn,dfs(i,x,dep+1));
    return minn;
}
int solve(){
    int ans=n;
    for(int i=0;i<(1<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++)cnt+=(((1<<j)&i)>0);
        if(cnt!=k)continue;
        for(int j=1;j<=n;j++)f[j]=j;
        for(int j=1;j<=n;j++)for(auto l:e[j])if((i&(1<<(j-1)))&&(i&(1<<(l-1))))merge(j,l);
        cnt=0;
        for(int j=1;j<=n;j++)cnt+=(f[j]==j&&(i&(1<<(j-1))));
        if(cnt>2)continue;
        for(int j=1;j<=n;j++)book[j]=(i&(1<<(j-1)));
        int maxx=0;
        for(int j=1;j<=n;j++)maxx=max(maxx,dfs(j,j));
        ans=min(ans,maxx);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        if(c<=3)cout<<solve()<<endl;
        else if(c==13||c==14){
            n=(n+1)/2+2;
            int ans=0;
            for(ans=0;ans<=n;ans++)if(ans*4-1+k>=n)break;
            cout<<min((n-k+1)/2,ans);
        }
    }
    return 0;
}
/*
100+100+48+25=273
I don't want to lose any score.
*/