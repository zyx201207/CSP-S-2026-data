#include <bits/stdc++.h>
using namespace std;
struct edge{
    int a,t;
};
struct data{
    int x,t;
};
vector<edge> graph[510];
vector<edge> rgraph[500010];
bool cmp(edge x,edge y){
    return x.t<y.t;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+10]={};
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int a,t;
            cin>>a>>t;
            graph[i].push_back({a,t});
            rgraph[a].push_back({i,t});
        }
        sort(graph[i].begin(),graph[i].end(),cmp);
    }
    for(int i=1;i<=q;++i){
        int x,y;
        cin>>x>>y;
        queue<data> q;
        q.push(data{x,w[x]});
        int ans=1e9;
        while(!q.empty()){
            data head=q.front();
            int px=head.x,pt=head.t;
            q.pop();
            // cout<<px<<' '<<pt<<endl;
            if(px==y){
                ans=min(ans,pt+w[px]);
                break;
            }
            // 现在已经在站厅并要去到站台，所以需要选一个线路然后过去，graph的逻辑是从线路到地铁站所以要用rgraph
            sort(rgraph[px].begin(),rgraph[px].end(),cmp);
            for(auto i:rgraph[px]){
                // 那此时的时间显而易见为pt+i.t
                // 然后还要选择下一站，这样才能push，此时就是相反了，需要从线路到地铁站，那当然是graph
                for(auto j:graph[i.a]){
                    // 可知，去到的地点（下一站的编号）为j.a；此时步行时间增加了j.t
                    q.push(data{j.a,pt+i.t+j.t});
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
// 如答案第一次出现就结束程序，有概率会出现非最优答案，但若使程序完整运行会高兴的TLE，还是决定WA好一点，虽然也会TLE(doge)