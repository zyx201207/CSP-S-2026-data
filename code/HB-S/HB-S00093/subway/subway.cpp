#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN=505;
const int MAXM=5e5+5;
vector<pair<int,int>>station[MAXM];//<line,cost>换乘费用
int line[MAXN][MAXM];//<line,station>
bool vis[MAXN];
int w[MAXM];//进站费用
int ans=INT_MAX;
int k[MAXN];//第i条经过的地铁站数
void dfs(int nowstation,int nowline,int target,int dirct,int nowans){
    vis[nowline]=1;
    if(nowans>ans)return;
    if(nowstation==target){
        for(int i=0;i<station[target].size();i++){
            if(station[target][i].first==nowline){nowans+=station[target][i].second;break;}
        }
        nowans+=w[nowstation];
        ans=min(ans,nowans);
        return;
    }
    int index;
    for(int i=0;i<k[nowline];i++){
        if(line[nowline][i]==nowstation){index=i;break;}
    }
    if(station[nowstation].size()>1){
		int index2;
		for(int i=0;i<station[nowstation].size();i++){
            if(station[nowstation][i].first==nowline){
				index2=i;
				break;
            }
        }
        for(int i=0;i<station[nowstation].size();i++){
            if(station[nowstation][i].first!=nowline && !vis[station[nowstation][i].first]){
                dfs(nowstation,station[nowstation][i].first,target,1,nowans+station[nowstation][index2].second+station[nowstation][i].second);
                dfs(nowstation,station[nowstation][i].first,target,-1,nowans+station[nowstation][index2].second+station[nowstation][i].second);
            }
        }
    }
    if(index+dirct<0 || index+dirct>=k[nowline])return;
    dfs(line[nowline][index+dirct],nowline,target,dirct,nowans);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[m];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>line[i][j];
            int tmp;
            cin>>tmp;
            station[line[i][j]].push_back({i,tmp});
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        ans=INT_MAX;
        int x,y;
        cin>>x>>y;
        for(int i=0;i<station[x].size();i++){
            dfs(x,station[x][i].first,y,1,w[x]+w[y]+station[x][i].second);
            dfs(x,station[x][i].first,y,-1,w[x]+w[y]+station[x][i].second);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//椎名真昼天下第一！
