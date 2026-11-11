#include<bits/stdc++.h>
using namespace std;
int c,t;
    vector<int> g[1000005];
    int dis[100005][100005];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<bool> cs(n,0);
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> s(k);
    clock_t c=clock();
    while(rand()^rand()>rand()|rand()){
        if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
        for(int i=0;i<k;++i){
            while(1){
                int xx=rand();
                if(!cs[xx]){s[i]=xx;cs[xx]=1;break;}
                if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
            }
                    if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
        }
        for(int i=0;i<k;++i){if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
            queue<int> q;
            q.push(s[k]);
            int diss=0;
            while(q.empty()){
                int u=q.back();
                q.pop();
                for(auto j:g[u]){
                    q.push(j);
                            if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
                    dis[u][j]=dis[u][j]=diss;
                    diss++;
                }
            }
        }
        g[0].clear();
        for(int i=0;i<k;++i)g[0][i]=0x3f;if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
        for(int i=0;i<k;++i){
            for(int j=0;j<i;++j)
            {        if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
            g[0][i]=min(g[0][i],dis[j][i]);}
        }
                if(c-clock()>CLOCKS_PER_SEC/5){
            cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
            return;
        }
        cout<<*max_element(g[0].begin(),g[0].end());
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;++i){
        srand(time(0));
        srand(time(0)^rand());
        cout<<(rand()*rand()^rand()^rand()%(rand()+1)-rand()|rand());
    }
}