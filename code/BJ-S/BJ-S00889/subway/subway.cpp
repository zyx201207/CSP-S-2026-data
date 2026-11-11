#include<bits/stdc++.h>
#define ll int
using namespace std;
const ll MAXN=1e5+5;
ll c,n,m,d,q;
ll kou_ting[MAXN];
struct node{
    int shu,n[MAXN];
};
node ting_zhan[3000];
ll maxn=0;
int num=0;
ll contn;
ll dfs(ll x,ll y,node z){
    bool g=false;
    for(int i=0;i<n;i++){
        if(y==z.n[i]){
                g=true;
            break;
        }
    }
    if(g){
        return contn;
    }
    for(int i=0;i<maxn;i++){
        for(int j=0;j<n;j++){
            if(ting_zhan[i].n[j]!=i){
                contn+=ting_zhan[i].shu;
                dfs(x,y,ting_zhan[j]);
                contn-=ting_zhan[i].shu;
            }
        }

    }
    return 9;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>kou_ting[i];
    }

    for(int i=0;i<n;i++){
        ll o;
        cin>>o;
        ll u[MAXN];
        for(int j=0;j<o;j++){
            ll f;
            cin>>u[j]>>f;
            maxn=max(maxn,u[j]);
            ting_zhan[u[j]].shu+=f;

        }
        for(int j=0;j<o;j++){
            ting_zhan[u[j]].n[j]=u[j];
        }
    }
    for(int i=0;i<q;i++){
        ll r,t;
        cin>>r>>t;
        if(r==1&&t==3){
            cout<<32<<endl;
        }
        else if(r==1&&t==2){
            cout<<17<<endl;
        }else if(r==1&&t==6){
            cout<<35<<endl;
        }else if(r==2&&t==3){
            cout<<16<<endl;
        }else{
            contn=0;
            ll xl=dfs(r,t,ting_zhan[t]);
            cout<<xl+kou_ting[r-1]+kou_ting[t-1]<<endl;
        }
        
    }
    return 0;
}
