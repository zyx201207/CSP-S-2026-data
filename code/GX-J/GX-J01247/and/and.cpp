#include<bits/stdc++.h>
using namespace std;

int AND(int x,int y){
    vector<bool> vx,vy;
    while(x){
        vx.push_back(x%2);
        x/=2;
    }
    while(y){
        vy.push_back(y%2);
        y/=2;
    }

    vector<bool> rst;///result
    for(int i=0;i<min( vx.size(),vy.size() );i++){
        if(vx[i]==1&&vy[i]==1) rst.push_back(1);
        else rst.push_back(0);
    }

    int rstInt=0;
    for(int i=0;i<rst.size();i++){
        if(rst[i]) rstInt+=pow(2,i);
    }
    return rstInt;
}

int n,a[2005],m;
long long ans=0;

vector<int> tmpv;
bool vis[2005];
void dfs(vector<int> l){
    if(l.size()>=m){
        int qwe=l[0];
        for(int i=1;i<l.size();i++){
            qwe=AND(qwe,l[i]);
        }
        if(qwe>ans) ans=qwe;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            l.push_back(a[i]);
            dfs(l);
            vis[i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    dfs(tmpv);
    cout<<ans;
    return 0;
}
