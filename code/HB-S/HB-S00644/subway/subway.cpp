#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500001],transfer[501][501],ansed=-1,ans[501];
unordered_map<int,int>t[500001];
vector<int>station[500001],metro[501];
struct node{
    int from,to,ans,order;
}que[100001];
bool cmp(node u,node v){
    return u.from<v.from;
}
bool cmp2(node u,node v){
    return u.order<v.order;
}
priority_queue<pair<int,int>>qq;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(transfer,0x3f,sizeof transfer);
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;++i){
        cin>>k;
        for(int j=1,u,v;j<=k;++j){
            cin>>u>>v;
            metro[i].push_back(u);
            t[u][i]=v;
            for(int k=0;k<(int)station[u].size();++k){
                transfer[i][station[u][k]]=min(transfer[i][station[u][k]],v+t[u][station[u][k]]);
                transfer[station[u][k]][i]=min(transfer[station[u][k]][i],v+t[u][station[u][k]]);
            }
            station[u].push_back(i);
        }
    }
    for(int i=1;i<=q;++i){
        cin>>que[i].from>>que[i].to;
        que[i].order=i;
    }
    sort(que+1,que+1+q,cmp);
    for(int i=1;i<=q;++i){
        if(que[i].to==que[i].from){
            cout<<"0\n";
            continue;
        }
        if(ansed!=que[i].from){
            memset(ans,0x3f,sizeof ans);
            while(!qq.empty()){
                qq.pop();
            }
            for(int j=0;j<(int)station[que[i].from].size();++j){
                qq.push({t[que[i].from][station[que[i].from][j]],station[que[i].from][j]});
                ans[station[que[i].from][j]]=t[que[i].from][station[que[i].from][j]];
            }
            while(!qq.empty()){
                pair<int,int>now=qq.top();
                qq.pop();
                if(now.first>ans[now.second]){
                    continue;
                }
                for(int j=0;j<=n;++j){
                    if(j==now.second){
                        continue;
                    }
                    if(transfer[j][now.second]!=0x3f3f3f3f&&(now.first+transfer[j][now.second]<ans[j]||ans[j]==0x3f3f3f3f)){
                        ans[j]=now.first+transfer[j][now.second];
                        qq.push({ans[j],j});
                    }
                }
            }
            ansed=que[i].from;
        }
        int minn=LONG_LONG_MAX;
        for(int j=0;j<(int)station[que[i].to].size();++j){
            minn=min(ans[station[que[i].to][j]]+t[que[i].to][station[que[i].to][j]],minn);
        }
        que[i].ans=minn+w[que[i].from]+w[que[i].to];
    }
    sort(que+1,que+1+q,cmp2);
    for(int i=1;i<=q;++i){
        cout<<que[i].ans<<'\n';
    }
    return 0;
}
