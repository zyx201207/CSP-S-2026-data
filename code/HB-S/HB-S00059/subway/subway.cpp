#include <bits/stdc++.h>

/*
zha pi ba zhe ti
*/

using namespace std;
#define vec vector
#define For(n) for(int i=0;i<n;++i)
#define go first
#define time second

struct subway_stop
{
    int stop_to_entrance;
    vec<pair<int,int>> stop_to_ways;
    vec<int> connect_to; 
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto f1 = freopen("subway.in","r",stdin);
    auto f2 = freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    vec<subway_stop> stop(m+1);
    For(m) cin>>stop[i+1].stop_to_entrance;
    vec<vec<int>> ways(n+1);
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int a,t;
            cin>>a>>t;
            ways[i].push_back(a);
            stop[a].stop_to_ways.push_back({i,t});
        }
    }

    while (q--)
    {
        int x,y;
        cin>>x>>y;
        
        vec<bool> visited(m+1,false);
        visited[x]==true;
        vec<int> time(m+1,INT_MAX);
        time[x]=stop[x].stop_to_entrance;
        queue<int> q;
        q.push(x);
        while (!q.empty())
        {
            auto cx = q.front();
            q.pop();
            for(auto way : stop[cx].stop_to_ways){
                for(auto destination : ways[way.go]){
                    if (!visited[destination]){
                        q.push(destination);
                        visited[destination]=true;
                        time[destination]=min(stop[destination].stop_to_ways[way.first].second,destination);
                    }
                }
            }
        }
        cout<<time[y]+stop[y].stop_to_entrance<<endl;
        
    }
    

    return 0;
}