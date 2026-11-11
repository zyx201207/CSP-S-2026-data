#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minn,c,t,ans,n,x,y,tick[2000086],ind[2000086],dis[2000086];
vector<int> tree[2000086];
struct node{
    int id,dis;
};
queue<node> q;
void dfs(int x,int f){
    
}
bool check(int r){
    for(int i=1;i<=n;i++){
        if(ind[i]==1)q.push(node{i,0});
        dis[i]=-1;
    }
    while(!q.empty()){
        node no=q.front();
        q.pop();
        if(no.dis==r)continue;
        for(int to:tree[no.id]){
            if(dis[to]==-1){
                dis[to]=no.dis+1;
                q.push(node{to,dis[to]});
            }
        }
    }

    return 0;
}
int main(){
    cin >> c >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            tree[i].clear();
            ind[i]=0;
        }
        for(int i=1;i<n;i++){
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
            ind[x]++;
            ind[y]++;
        }
        int l=1,r=n;
        while(l<=r){
            
        }
        cout << ans;
    }
    
    return 0;
}