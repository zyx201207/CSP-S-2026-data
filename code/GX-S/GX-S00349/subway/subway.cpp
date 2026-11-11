#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define c(x) cout<<x<<endl
#define fet(x) const int fet=x

using namespace std;

fet(2e3);
int c,n,m,d,q;
struct node { int x,y,id; } r[100010];
bool cmp(node a,node b){ return a.x<b.x; }
bool pmc(node a,node b){ return a.id<b.id; }
int ans[fet];
int k[fet],w_m[fet];
vector<int> a[fet],t[fet];
vector<pair <int,int> > v[fet];

void p_(int x,int y,int w){
    v[x].push_back({y,w});
    v[y].push_back({x,w});
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w_m[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back(-1);
        t[i].push_back(-1);
        for(int j=1;j<=k[i];j++){
            int tmp1,tmp2; cin>>tmp1>>tmp2;
            a[i].push_back(tmp1);
            t[i].push_back(tmp2);
        }
    }
    for(int i=1;i<=q;i++) cin>>r[i].x>>r[i].y,r[i].id=i;

    for(int i=1;i<=m;i++){
        p_(1,1+m,w_m[i]); //xia di tie
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int o=1;o<=k[i];o++){
                p_(a[i][j]+m,a[i][o]+m,t[i][j]+t[i][o]);
            }
        }
    }

    sort(r+1,r+1+q,cmp);
    int pi=0;

    for(int s=1;s<=m;s++){
        priority_queue<pair <int,int> > lis;
        bool vis[n<<1]={};
        int step[n<<1]={};
        lis.push({0,s});
        memset(step,inf,sizeof(step));
        while(lis.size()){
            pair<int,int> now=lis.top(); lis.pop(); vis[now.second]=true;
            for(auto nxt : v[now.second] ){
                c(-11);
                if(vis[nxt.second]) continue;
                step[nxt.first]=
                min(step[nxt.first],step[now.second]+nxt.second);
                lis.push({step[nxt.first],nxt.second});
            }
        }
        while(++pi){
            if(r[pi].x!=s){
                pi--; break;
            }
            ans[pi]=step[r[pi].y];
        }
    }
    for(int i=1;i<=pi;i++){
        c(ans[i]);
    }
    return 0;
}
