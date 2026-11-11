#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
const int INT_M=1e9;
int dist[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    vector<int> t(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dist[i][j]=INT_M;
        }
    }
    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<pair<int,int>> xianlu(0);
        for(int j=0;j<k;j++){
            int a;
            int t;
            cin>>a>>t;
            xianlu.push_back(make_pair(a,t));
        }
        for(auto j:xianlu){
            for(auto m:xianlu){
                dist[j.first][m.first]=min(j.second+m.second,dist[j.first][m.first]);
                dist[m.first][j.first]=min(j.second+m.second,dist[m.first][j.first]);
            }
        }
    }
    vector<pair<int,int>> plan(q);
    for(int i=0;i<q;i++){
        cin>>plan[i].first>>plan[i].second;
    }
    //Floyd
    for(int w=1;w<m+1;w++){
        for (int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
                dist[i][j]=min(dist[i][w]+dist[w][j],dist[i][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        cout<<t[plan[i].first] + t[plan[i].second] + dist[plan[i].first][plan[i].second]<<"\n";
    }
    return 0;
}
