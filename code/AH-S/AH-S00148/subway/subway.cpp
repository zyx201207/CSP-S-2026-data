#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+5;
int w[N]={};
vector<pair<int,int> > v[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int last=0;
        int lastt=0;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            v[last].push_back({a,t});
            v[a].push_back({last,lastt});
            last=a;
            lastt=t;
        }
    }
    if(q<=50){
        while(q--){
            int x,y;
            cin>>x>>y;
            queue<pair<int,int> >q;
            q.push({x,0});
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i==y){
                    cout<<j+w[x]+w[y]<<'\n';
                    break;
                }
                for(int k=0;k<v[i].size();k++){
                    q.push({v[i][k].first,j+v[i][k].second});
                }
            }
        }
    }else{
        while(q--){
            int x,y;
            cin>>x>>y;
            int ans=0;
            for(int i=x;i<=y;i++){
                ans+=v[i][0].second;
            }
            cout<<w[x]+w[y]+ans<<'\n';
        }
    }
    return 0;
}
