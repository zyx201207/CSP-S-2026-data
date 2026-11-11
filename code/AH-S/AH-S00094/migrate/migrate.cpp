#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
int c,t;
ll n,d,ans,x[maxn],dis[maxn],num[maxn];
bitset<maxn> done;
struct node{
    int id;
    ll dis;
    bool operator < (const node b)const{
        return dis>b.dis;
    }
};
void dij(int k){
    //cout<<k<<"---"<<endl;
    memset(dis,0x3f,sizeof(dis));
    memset(num,0,sizeof(num));
    done.reset();
    //cout<<dis[0]<<endl;
    priority_queue<node> q;
    q.push({k,0});
    dis[k]=0;
    num[k]=1;
    while(!q.empty()){
        node u=q.top();
        q.pop();
        if(done[u.id]){
            continue;
        }
        //cout<<u<<endl;
        done[u.id]=1;
        for(int i=u.id+1;i<=n;++i){
            if(x[i]<=d+x[u.id]){
                if(dis[i]>u.dis+1){
                    num[i]=num[u.id];
                    dis[i]=u.dis+1;
                    q.push({i,dis[i]});
                }
                else if(dis[i]==u.dis+1){
                    num[i]+=num[u.id];
                }
                //cout<<i<<' '<<dis[i]<<' '<<num[i]<<endl;
            }
            else break;
        }
    }
    for(int i=k+1;i<=n;++i){
        //out<<num[i]<<' ';
        ans+=(num[i]==2);
    }
    //cout<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
        }
        for(int i=1;i<=n;++i){
            dij(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
//40