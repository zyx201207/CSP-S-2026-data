#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int a[2000005];
vector<int> g[2000005];
vector<int> mn[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    int n,d;
    while(T--){
        for(int i=1;i<=n;i++){
            g[i].clear();
            mn[i].clear();
        }
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int j=i+1;
            while(j<=n&&a[j]-a[i]<=d){
                g[i].push_back(j);
                j++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            queue<pii> q;
            q.push({i,0});

            while(!q.empty()){
                auto t=q.front();
                q.pop();
                for(auto v:g[t.first]){
                    q.push({v,t.second+1});
                    if(!mn[v].empty()&&t.second+1<=mn[v].front()){
                        mn[v].clear();
                        mn[v].push_back(t.second+1);
                        continue;
                    }
                    if(mn[v].empty())mn[v].push_back(t.second+1);
                    else if(t.second+1==mn[v].front())mn[v].push_back(t.second+1);
                }
            }

            for(int i=1;i<=n;i++){
                if(mn[i].size()==2){
                    ans++;
                }
                mn[i].clear();
            }

        }
        cout<<ans<<'\n';
    }

    return 0;
}
