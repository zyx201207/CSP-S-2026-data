#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
long long c,n,m,q,d,t[1000][1000],a[1000][1000],t1[N],k1[N];
long long dis[N],disd[N];
struct be{
    long long ii,tim;
};
vector<be>ji[N];
void di(long long x){
    deque<long long> q;
    for(auto v:ji[x]){
        q.push_back(v.ii);
        for(int i=1;i<=k1[v.ii];i++){
            dis[a[v.ii][i]]=v.tim;
            disd[a[v.ii][i]]=v.ii;
        }
    }
    while(!q.empty()){
        auto k=q.front();
        q.pop_front();
        for(int i=1;i<=k1[k];i++){
            for(auto v:ji[a[k][i]]){
                if(v.ii==k)
                continue;
                long long timee=t[k][i]+v.tim;
                bool vi=false;
                for(int j=1;j<=k1[v.ii];j++){
                    if(dis[a[v.ii][j]]>timee+dis[a[k][i]]){
                        dis[a[v.ii][j]]=timee+dis[a[k][i]];
                        disd[a[v.ii][j]]=v.ii;
                        vi=true;
                    }
                }
                if(vi){
                    q.push_back(v.ii);
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k1[i];
        for(int j=1;j<=k1[i];j++){
            cin>>a[i][j]>>t[i][j];
            ji[a[i][j]].push_back(be{i,t[i][j]});
        }
    }
    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        for(int i=1;i<=m;i++){
            dis[i]=0x3f3f3f3f3f3f3f3f;
        }
        di(x);
        long long sds;
        for(auto v:ji[y]){
            if(v.ii==disd[y]){
                cout<<t1[x]+dis[y]+v.tim+t1[y]<<endl;
            }
        }
    }
    return 0;
}
