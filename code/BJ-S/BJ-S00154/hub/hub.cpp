#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+100;
const int N=1000;
int c,t;
int n,kk;
int v[N];
int ans=INF;
vector<int> e[N];
queue<pair<int,int> > q;
int sn(int x){
    int re=0;
    while(x){
        if(x%2==1) re++;
        x/=2;
    }
    return re;
}
void dfs(int x){
    v[x]=1;
    for(int y : e[x]){

        if(!v[y]){
            v[y]=1;
            dfs(y);
        }
    }
}
int main(){

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=INF;

        cin>>n>>kk;
        for(int i=0;i<=n;i++){
            v[i]=0;
            e[i].clear();
        }
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        for(int k=0;k<(1<<n);k++){
            if(sn(k)!=kk){
                continue;
            }
            int f=0;
            for(int i=1;i<=n;i++){
                if((k>>(i-1))&1){
                    if(!v[i]){
                        dfs(i);
                        f++;
                    }
                }
            }
            if(f>2) continue;
            while(q.size()) q.pop();
            for(int i=0;i<=n;i++) v[i]=0;
            for(int i=1;i<=n;i++){
                if((k>>(i-1))&1){
                    q.push(make_pair(0,i));
                    v[i]=1;
                    //cout<<i<<"*";
                }
            }
            //cout<<"       "<<k<<q.size()<<endl;
            int dt=0;
            while(q.size()){
                int x=q.front().second;
                int y=q.front().first;
                q.pop();
                dt=max(dt,y);
                //cout<<dt<<"   ";
                for(int u : e[x]){
                    if(!v[u]){
                        v[u]=1;
                        q.push(make_pair(1+y,u));
                    }
                }
            }
            //cout<<endl<<ans<<" "<<dt<<endl;
            ans=min(ans,dt);

        }
        cout<<ans<<endl;

    }
    return 0;
}
