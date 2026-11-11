/*
童如不知道自己在掌门印中究竟有没有留下什么，也不知道韩木椿看见了没有，更无从探知他若是知道……该作何感想。
仿佛甜只有一瞬，苦却苦了很多年。
再相见，是生人不可即的忘忧谷。韩木椿以自己苟延残喘的元神，将童如的一魂困在忘忧谷。
其实不过是画地为牢。即使只剩残魂，童如也是问鼎过北冥的人。真要挣脱，韩木椿那对他来说始终稀松平常的修为不见得能起什么用。
不过纵然千刀万剐，童如也十分甘之若饴。他有些诚惶诚恐地接受了受刑于天地、魂飞魄散的下场。因为和某人同生共死，简直是求而不得。
只是再没有百花酒了。
童如以前总觉得他这宝贝徒弟有些随波逐流，后来他才明白，凡人也好，修士也罢，一辈子只要有那么几件事九死不悔就够了，其余旁枝末节就由他去了。
他始终也没有问一句“这些年来，你在掌门印中看到了什么”。
直到魂归天地的一刻。
那一刻，韩木椿突然亲密过头地拉住了他的手，望向他的眼裏好像有一片浩渺的星河。
直道相思了无益，未妨惆怅是清狂。
相必若能死而无憾，就算是飞升了吧。
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=1000006;
int id,T,n,k;
vector<int>e[N];
int f[N];
int find(int x){
    return (f[x]==x)?x:(f[x]=find(f[x]));
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>id>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int u,v,i=n;--i;e[u].push_back(v),e[v].push_back(u))cin>>u>>v;
        if(n<=10){
            bool key[11];
            int dis[11][11];
            for(int i=1;i<=n;i++){
                memset(key,0,sizeof(key));
                dis[i][i]=0,key[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int u:e[x])
                        if(!key[u])key[u]=1,dis[i][u]=dis[i][x]+1,q.push(u);
                }
            }
            int ans=n;
            for(int mask=0;mask<(1<<n);mask++){
                if(__builtin_popcount(mask)!=k)continue;
                for(int j=0;j<n;j++)key[j+1]=(mask>>j&1);
                int cnt=0;
                for(int j=1;j<=n;j++)f[j]=j;
                for(int j=1;j<=n;j++)
                if(key[j]){
                    for(int t:e[j])
                        if(key[t])f[find(t)]=find(j);
                }
                for(int j=1;j<=n;j++)
                    if(key[j]&&f[j]==j)cnt++;
                if(cnt>2)continue;
                int mx=0;
                for(int j=1;j<=n;j++){
                    int mn=n;
                    for(int t=1;t<=n;t++)
                        if(key[t])mn=min(mn,dis[t][j]);
                    mx=max(mx,mn);
                }
                ans=min(ans,mx);
            }
            cout<<ans<<'\n';
            continue;
        }
        cout<<(k<n)<<'\n';
    }
    return 0;
}
/*
在树上选出 k 个点形成不超过 2 个连通块,最小化其他点到这 k 个点中最近一个的距离的最大值.
容易想到二分,转化为每个点到这 k 个点中最近一个的距离都不超过 lim.
即对每个点,其 lim 半径范围内都要选出点.
或者说?
*/