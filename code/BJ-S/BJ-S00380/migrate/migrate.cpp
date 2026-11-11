#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000010];
int ms[2000010];//minstep
int mcs[2000010];//minstep cishu
vector<int> v[2000010];
int n,d;
int sum;
void bfs(int start){
    queue<pair<int,int>> q;//l step
    q.push({start,0});
    while(!q.empty()){
        auto s=q.front();
        int l=s.first,step=s.second;
        q.pop();
        if(ms[l]==0) ms[l]=step,mcs[l]=1;
        else if(ms[l]==step) mcs[l]++;
        for(int i=0;i<v[l].size();i++){
            q.push({v[l][i],step+1});
        }
    }
    for(int i=1;i<=n;i++){
        if(mcs[i]==2) sum++;
    }
    memset(ms,0,sizeof ms);
    memset(mcs,0,sizeof mcs);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            while(v[i].size()){v[i].pop_back();}
        }
        sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d) v[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++) bfs(i);
        cout<<sum<<"\n";
    }
}
