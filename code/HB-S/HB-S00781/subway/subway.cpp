#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,INF=0x7f7f7f7f;
int c,n,m,d,q;
int w[N];
struct node{
   int u,v,t,tag;
};
vector<node> e[N];
int dist[N];
void dijsktra(int s){
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    dist[s]=0;
    priority_queue<pair<ll,node>,vector<pair<ll,node>>,greater<pair<ll,node>>> pq;

}
int main(){}
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;i++){
            int a,t;
            cin>>a>>t;

        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
