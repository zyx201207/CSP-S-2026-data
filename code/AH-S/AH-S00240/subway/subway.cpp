#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c,n,m,d,q;
struct node{
    int va,to;
};
vector<node> G[N];
int w[N];
int dis[510][N];
void spfa(int st){
    bool flag[N]={};
    queue<int> q;
    q.push(st);
    flag[st]=1;
    dis[st-m][st]=0;
    int cnt=0;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        flag[tmp]=0;
        /*
        for(int i=0;i<G[tmp].size();i++){
            if(dis[st-m][G[tmp][i].to]>dis[st-m][tmp]+G[tmp][i].va){
                cnt++;
               dis[st-m][G[tmp][i].to]= dis[st-m][tmp]+G[tmp][i].va;
               if(flag[G[tmp][i].to]==0){
                    flag[G[tmp][i].to]=1;
                    q.push(G[tmp][i].to);
               }
            }
        }
        */
        for(auto i:G[tmp]){
            if(dis[st-m][i.to]>dis[st-m][tmp]+i.va){
                dis[st-m][i.to]=dis[st-m][tmp]+i.va;
                if(flag[i.to]==0){
                    flag[i.to]=1;
                    q.push(i.to);
                }
            }
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=0x3f3f3f3f;
		}
	}
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int ai,ki;
            cin>>ai>>ki;
            G[ai].push_back({ki,m+i});
            G[m+i].push_back({ki,ai});
        }
    }
    for(int i=1;i<=n;i++){
        spfa(i+m);
    }
    for(int i=1;i<=q;i++){
        int x,y;
        int ans=0x3f3f3f3f;
        cin>>x>>y;
        for(int j=0;j<G[x].size();j++){
            ans=min(ans,G[x][j].va+dis[G[x][j].to-m][y]);
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
