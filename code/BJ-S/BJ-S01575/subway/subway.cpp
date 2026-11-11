//te shu xing zhi A
//20
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int qq[100005],zz[100005];
int dist[505];
vector<int> a[505],t[505];
// struct node{
//     int x,y,w;
// }
vector<pair<int,int> > eg[505];
void slv(){
    //te shu xing zhi A!!!
    vector<int> jde[505];
    vector<int> qd;
    map<pair<int,int>,int> yydy;
    for (int i=1;i<=q;i++){
        cin>>qq[i]>>zz[i];
        jde[qq[i]].push_back(zz[i]);
        if (jde[qq[i]].size()==1) qd.push_back(qq[i]);
    }
    for (int i=1;i<=n;i++){
        if (k[i]<2) continue;
        int jjj=t[i][1]+t[i][2];
        eg[a[i][1]].push_back({a[i][2],jjj});
        eg[a[i][2]].push_back({a[i][1],jjj});
    }
    for (int fff=0;fff<qd.size();fff++){
        int s=qd[fff];
        for (int i=1;i<=m;i++){
            dist[i]=10000000000000000;
        }
        dist[s]=0;
        priority_queue<pair<int,int> > q;
        q.push({0,s});
        while (!q.empty()){
            auto hd=q.top();
            q.pop();
            int ldis=-hd.first,lwz=hd.second;
            for (auto nxt:eg[lwz]){
                int nto=nxt.first,nbian=nxt.second;
                if (ldis+nbian<dist[nto]){
                    dist[nto]=ldis+nbian;
                    q.push({-dist[nto],nto});
                }
            }
        }
        vector<int> dislin;
        dislin.push_back(0);
        for (int i=1;i<=m;i++){
            // if (i==s) continue;
            dislin.push_back(dist[i]);
        }
        for (int pp:jde[s]){
            yydy[{s,pp}]=dist[pp];
        }
    }
    for (int i=1;i<=q;i++){
        cout<<w[qq[i]]+w[zz[i]]+yydy[{qq[i],zz[i]}]<<"\n";
    }
    return ;
}
signed main(){
    // scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for (int j=1;j<=k[i];j++){
            int aij,tij;
            cin>>aij>>tij;
            a[i].push_back(aij);
            t[i].push_back(tij);
        }
    }
    if (c>=7 and c<=11 or c==0){
        slv();
    }
    return 0;
}