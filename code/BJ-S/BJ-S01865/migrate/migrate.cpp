#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,cnt,ans;
long long a[2000001];
vector<long long> g[5001],e[5001];
long long dis[5001],ways[5001],deg[5001];
map<long long,long long> mp;
long long nxt[2000001],lst[2000001];
queue<long long> q;
void bfs(long long s){
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        long long x=q.front();
        q.pop();
        for(auto v:g[x]){
            if(dis[v]>dis[x]+1){
                dis[v]=dis[x]+1;
                q.push(v);
            }
        }
    }
}
void toposort(long long s){
    q.push(s);
    ways[s]=1;
    while(!q.empty()){
        long long x=q.front();
        q.pop();
        for(auto v:e[x]){
            ways[v]+=ways[x];
            if(--deg[v]==0){
                q.push(v);
            }
        }
    }
    for(long long i=1;i<=n;i++){
        if(ways[i]==2){
            ans++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            cin>>n>>d;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
                g[i].clear();
            }
            for(long long i=1;i<=n;i++){
                for(long long j=1;j<=n;j++){
                    if(abs(a[i]-a[j])<=d){
                        g[i].push_back(j);
                    }
                }
            }
            ans=0;
            for(long long i=1;i<=n;i++){
                for(long long j=1;j<=n;j++){
                    dis[j]=(1<<30);
                    e[j].clear();
                }
                bfs(i);
                for(long long j=1;j<=n;j++){
                    for(auto v:g[j]){
                        if(dis[v]==dis[j]+1){
                            e[j].push_back(v);
                            deg[v]++;
                        }
                    }
                }
                toposort(i);
                for(long long j=1;j<=n;j++){
                    deg[j]=0,ways[j]=0;
                }
            }
            cout<<ans/2<<endl;
        }
    }
    else if(c<=12){
        while(t--){
            cin>>n>>d;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
            }
            long long lc=min(d/(a[2]-a[1]),n-1);
            if(lc<=1){
                cout<<0<<endl;
            }else{
                cout<<max(n-2*lc+1,0ll)<<endl;
            }
        }
    }else{
        while(t--){
            cin>>n;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
            }
            mp.clear();
            long long j=n;
            for(long long i=n;i>=1;i--){
                while(j>i&&a[j]-a[i]>d){
                    j--;
                }
                nxt[i]=j;
            }
            j=1;
            for(long long i=1;i<=n;i++){
                while(j<i&&a[i]-a[j]>d){
                    j++;
                }
                lst[i]=j;
            }
            long long ans=0;
            for(long long i=n;i>=1;i--){
                if(nxt[i]>i+1){
                    ans+=mp[nxt[i]-1];
                }
                mp[lst[i]]++;
            }
            cout<<ans<<endl;
        }
    }
}
