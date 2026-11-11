#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const long long N=505,M=5e5+5,INF=1LL<<48;
long long c,n,m,d,q,sumk;
long long w[M];
struct node{
    long long a;
    long long t;
};
vector<node>subways[N];

// void yangli(){

// }

// long long dis[2005][2005];
// void yangli2(){
//     //jt
//     for(long long u=1;u<=m;++u)for(long long v=1;v<=m;++v)dis[u][v]=u==v?0:INF;
//     for(long long i=1;i<=n;++i){
//         for(long long ui=0,I=subways[i].size();ui<I;++ui){
//             for(long long vi=ui+1;vi<I;++vi){
//                 auto uobj=subways[i][ui];
//                 auto vobj=subways[i][vi];
//                 long long u=uobj.a;
//                 long long v=vobj.a;
//                 long long uTv=uobj.t+vobj.t;
//                 dis[u][v]=dis[v][u]=uTv;
//             }
//         }
//     }
//     for(long long i=1;i<=m;++i){
//         for(long long u=1;u<=m;++u){
//             for(long long v=1;v<=m;++v){
//                 dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
//             }
//         }
//     }
//     while(q--){
//         long long s,e;
//         cin>>s>>e;
//         cout<<w[s]+dis[s][e]+w[e]<<"\n";
//     }
// }

struct bian{
    long long v;
    long long w;
};
vector<bian>mp[M];
long long nodeMaxDis[M];
using stepNode=pair<long long,long long>;
long long pqueuebfs(long long s,long long e){
    priority_queue<stepNode,vector<stepNode>,greater<stepNode>>pqueue,temp;
    for(long long i=1;i<=m;++i)nodeMaxDis[i]=INF;
    nodeMaxDis[s]=0;
    // cout<<s<<" "<<e<<"\n";
    pqueue.push({0,s});
    while(pqueue.size()){
        // while(pqueue.size())cout<<pqueue.top().second<<" ",temp.push(pqueue.top()),pqueue.pop();
        // while(temp.size())pqueue.push(temp.top()),temp.pop();
        // cout<<"\n";
        auto now=pqueue.top();
        pqueue.pop();
        long long step=now.first,u=now.second;
        if(u==e)return w[s]+step+w[e];
        // cout<<u<<" <= \n";
        // if(nodeMaxDis[u]<step)continue;
        for(auto obj:mp[u]){
            long long v=obj.v;
            long long w=obj.w;
            // cout<<v<<":"<<w<<" ";
            long long newStep=step+w;
            if(nodeMaxDis[v]>newStep){
                nodeMaxDis[v]=newStep;
                pqueue.push({newStep,v});
            }
        }
        // cout<<"\n";
    }
    return-1;
}

void gaungyi(){
    for(long long i=1;i<=n;++i){
        for(long long ui=0,I=subways[i].size();ui<I;++ui){
            for(long long vi=ui+1;vi<I;++vi){
                auto uobj=subways[i][ui];
                auto vobj=subways[i][vi];
                long long u=uobj.a;
                long long v=vobj.a;
                long long uTv=uobj.t+vobj.t;
                mp[u].push_back({v,uTv});
                mp[v].push_back({u,uTv});
            }
        }
    }
    while(q--){
        long long s,e;
        cin>>s>>e;
        cout<<pqueuebfs(s,e)<<"\n";
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    // if(c==0)yangli();else
    if(true){
        cin>>n>>m>>d>>q;
        for(long long i=1;i<=m;++i)cin>>w[i];
        for(long long i=1,k,a,t;i<=n;++i){
            cin>>k;
            sumk+=k;
            while(k--){
                cin>>a>>t;
                subways[i].push_back({a,t});
            }
        }
        // if(m<=1000)yangli2();else
        if(true)gaungyi();
    }
    return 0;
}
/*
guang yi zui xiao sheng cheng shu?
zui duan lu wen ti?
ying gai shi jiang xian kan cheng jie dian qiu dis, gou zao zhan dian dao xian lu de fan she(fa[w] and value(fa[w],w)) zai xiao xin chu li ji ke
dan shi mei xie chu lai.
*/