#include<bits/stdc++.h>
using namespace std;
long long r,e,c,n,m,d,q,w[500001],ans,t[500001][501];
vector<long long>b[501],s[500001];
bool v[500001];
inline void dfs(long long u,long long wi,long long f){
    if(u==e){
        ans=min(ans,wi+w[e]+t[e][f]);
        return;
    }
    for(long long i=0;i<s[u].size();++i){
        for(long long j=0;j<b[s[u][i]].size();++j){
            long long c=b[s[u][i]][j];
            if(!v[c]){
                v[c]=true;
                if(f==-1){
                    dfs(c,wi+t[u][i],i);
                    //cout<<c<<' '<<wi+t[u][i]<<'\n';
                }if(i==f){
                    //dfs(c,wi,i);
                    //cout<<c<<' '<<wi+t[u][i]<<'\n';
                }else{
                    dfs(c,wi+t[u][f]+t[c][i],i);
                    //cout<<c<<' '<<wi+t[u][f]+t[u][i]<<'\n';
                }
                v[c]=false;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;++i){
        cin>>w[i];
    }
    for(long long i=0;i<n;++i){
        long long k,a;
        cin>>k;
        for(long long j=0;j<k;++j){
            cin>>a>>t[a][i];
            b[i].push_back(a);
            s[a].push_back(i);
        }
    }
    while(q--){
        cin>>r>>e;
        ans=LLONG_MAX;
        dfs(r,w[r],-1);
        cout<<ans<<'\n';
        /*
        memset(v,0,sizeof(v));
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >p;
        p.push({w[r],{r,-1}});
        v[r]=true;
        while(!p.empty()){
            int wi=p.top().first,u=p.top().second.first,f=p.top().second.second;
            p.pop();
            v[u]=false;
            if(u==e){
                cout<<wi+w[e]<<'\n';
                break;
            }
            for(int j:s[u]){
                for(int o:b[j]){
                    if(!v[o]){
                        v[o]=true;
                        if(j==f||f==-1){
                            p.push({wi,{o,j}});
                        }else{
                            p.push({wi+2*w[u],{o,j}});
                        }
                    }
                }
            }
        }
        */
    }
    return 0;
}
