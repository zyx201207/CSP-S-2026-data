#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct road{
    unordered_set<ll>a;
};
struct st{
    unordered_set<ll>b;
};
struct inf{
    ll name;
    ll rtr;
    inf(ll name0,ll rtr0){
        name=name0;
        rtr=rtr0;
    }
};
struct stat{
    vector<inf>ro;
};
struct node{
    ll fx;
    ll cost;
    ll xro;
    ll xst;
    node(ll fx0,ll cost0,ll xro0,ll xst0){
        fx=fx0;
        cost=cost0;
        xro=xro0;
        xst=xst0;
    }
};
bool operator<(const node &a,const node &b){
    a.cost>b.cost;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q,x,y;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    ll etr[m]={0};
    for(ll i=0;i<m;i++){
        scanf("%lld",&etr[i]);
    }
    priority_queue<node>way;
    struct stat iro[n];
    struct road rd[n];
    struct st stt[m];
    c=0;
    ll wz[n][m]={0};
    for(ll i=0;i<n;i++){
        scanf("%lld",&c);
        for(ll o=0;o<c;o++){
            scanf("%lld%lld",&x,&y);
            iro[i].ro.push_back(inf(x,y));
            rd[i].a.insert(x);
            wz[i][x]=iro[i].ro.size()-1;
            stt[x].b.insert(i);
        }
    }
    for(ll i=0;i<q;i++){
        scanf("%lld%lld",&x,&y);
        for(ll i=0;i<n;i++){
           if(rd[i].a.count(x)){
              way.push(node(1,etr[x]+iro[i].ro[wz[i][x]].rtr+etr[y],i,wz[i][x]));
              way.push(node(-1,etr[x]+iro[i].ro[wz[i][x]].rtr+etr[y],i,wz[i][x]));
           }
        }
        while(!way.empty()){
            auto cur=way.top();
            way.pop();
            ll fx1=cur.fx;
            ll cost1=cur.cost;
            ll xro1=cur.xro;
            ll xst1=cur.xst;
            if((cur.xst==iro[xro1].ro.size()||cur.xst==0)&&stt[iro[xro1].ro[xst1].name].b.size()==1){
               continue;
            }
            if(iro[xro1].ro[xst1].name+fx1==y){
               printf("%lld/n",cost1+iro[xro1].ro[xst1].rtr);
               break;
            }
            ll jb=iro[xro1].ro[xst1].name;
            for(ll i=0;i<n;i++){
                if(i==xst1&&wz[i][jb]!=0){
                    way.push(node(1,cost1+iro[i].ro[wz[i][jb]].rtr,xst1,wz[i][jb]));
                    way.push(node(-1,cost1+iro[i].ro[wz[i][jb]].rtr,xst1,wz[i][jb]));
                }
                else if(wz[i][jb]!=0){
                    way.push(node(1,cost1+iro[xro1].ro[wz[xro1][jb]].rtr+iro[i].ro[wz[i][jb]].rtr,i,wz[i][jb]));
                    way.push(node(-1,cost1+iro[xro1].ro[wz[xro1][jb]].rtr+iro[i].ro[wz[i][jb]].rtr,i,wz[i][jb]));
                }
            }
        }
    }
    return 0;
}
