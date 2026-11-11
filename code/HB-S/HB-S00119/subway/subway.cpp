#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+5;
int w[N];
int k[505];
int a[505][N],t[505][N];
vector<pair<int,int> > v[N];//which point are there in subway v and what is its step;
vector<pair<int,int> > sp[505];//what point can this subway reach(second) and how long is it(first)
bool wzmzl[505][N];
bool vis[N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            wzmzl[i][a[i][j]]=1;
            if(v[a[i][j]].size()){
                for(int o=0;o<v[a[i][j]].size();o++){
                    int to=v[a[i][j]][o].first;
                    int step=v[a[i][j]][o].second;
                    sp[i].push_back(make_pair(step+t[i][j],to));
                    sp[to].push_back(make_pair(step+t[i][j],i));
                }
            }
            v[a[i][j]].push_back(make_pair(i,t[i][j]));
        }
    }
    while(q--){
        memset(vis,0,sizeof vis);
        int x,y;
        cin>>x>>y;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //pq.push(make_pair(0,x));
        for(int i=1;i<=n;i++){
            if(wzmzl[i][x])pq.push(make_pair(0,i));
        }
        while(!pq.empty()){
            pair<int,int> now=pq.top();
            pq.pop();
            int nowf=now.first;//step
            int nows=now.second;//point
            vis[nows]=1;
            if(wzmzl[nows][y]==1){
                cout<<nowf<<endl;
                continue;
            }
            for(int i=0;i<sp[nows].size();i++){
                int get_to=sp[nows][i].second;
                int value=sp[nows][i].first;
                if(vis[get_to])continue;
                vis[get_to]=1;
                pq.push(make_pair(nowf+value,get_to));
            }
        }
    }
    return 0;
}
