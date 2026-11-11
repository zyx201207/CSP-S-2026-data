#include <iostream>
#include <vector>
using namespace std;
const int INF=1e9;
vector<bool> step;
int dfs(int cur,int cost,const vector<vector<int>> a,const vector<vector<int>> t,const vector<vector<int>> zt,int y){
    if(cur==y)
        return cost;
    if(step[cur]==true)
        return INF;
    step[cur]=true;
    int ans=INF;
    for(int i=0;i<a[cur].size();i++){
        for(int j=0;j<zt[a[cur][i]].size();j++){
            ans=min(ans,dfs(zt[a[cur][i]][j],cost+t[cur][i],a,t,zt,y));
        }
    }
    step[cur]=false;
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    step.resize(m);
    vector<int> w(m),k(n);
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    vector<vector<int>> a,t,zt(m);
    a.push_back({});
    t.push_back({});
    zt.push_back({});
    for(int i=0;i<n;i++){
        cin>>k[i];
        vector<int> tmpa(k[i]),tmpt(k[i]);
        for(int j=0;j<k[i];j++){
            cin>>tmpa[j]>>tmpt[j];
            zt[tmpa[j]].push_back(i+1);
        }
        a.push_back(tmpa),t.push_back(tmpt);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,w[x]+w[y],a,t,zt,y)<<endl;
    }
    return 0;
}
