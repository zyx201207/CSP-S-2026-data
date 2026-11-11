#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> intrance ;
vector<vector<int> > subway[5000];
vector<vector<int> > time1[5000];
vector<bool> vis(5000,false);
int ans=0;
void dfs(int x1,int x2){
    if(x1==x2){
        ans+=time1[x2][0];
    }
    if(vis[x1]){
        return 0;
    }
    if(subway[x1].size()>1){
        ans+=time1[x1][0];
        ans+=time1[x1][1];
    }
    vis[x1]=true;
    for(int i=0;i<subway[x1].size();i++){
        if(!vis[subway[x1][i]]){
            dfs(subway[x1][i],x2);
        }
    }
}
signed main(){
    freopen("subway.in","r" ,stdin);
    freopen("subway.out","w" ,stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int in;
    for(int i=0;i<m;i++){
        cin>>in;
        intrance.push_back(in);
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int a,t;
        cin>>a>>t;
        int prea=a;
        int pret=t;
        for(int j=2;j<=k;j++){
            cin>>a>>t;
            subway[prea].push_back(a);
            subway[a].push_back(prea);
            time1[pret].push_back(t);
            time1[t].push_back(pret);
        }
    }
    int x1,x2;
    vector<int> ansans;
    for(int i=0;i<q;i++){
        ans=0;
        cin>>x1>>x2;
        dfs(x1,x2);
        ansans.push_back(ans);
    }
    for(int i=0;i<q;i++){
        cout<<ansans[i]<<endl;
    }
    return 0;
}