#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#define MaxM 500005
#define MaxN 500
using namespace std;
int c,n,m,d,q;
int w[1+MaxM];
//int dist[500505][500505];
vector<pair<int,int> >edge[MaxM+MaxN];
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int ,int> > >qu;
int dist[500505];long long ans;int sp[400][400];
void sp_task1(){
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k;
    memset(sp,0x7f,sizeof(sp));
    for(int i=1;i<=n;i++){
        int a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            sp[a][m+a]=t;
            sp[m+a][a]=t;
        }
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            for(k=1;k<=n+m;k++){
                sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
            }
        }
    }
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<sp[x][y];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    if(c<=6){
        sp_task1();
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k;
    for(int i=1;i<=n;i++){
        int a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            edge[a].push_back(make_pair(t,m+a));
            edge[m+a].push_back(make_pair(t,a));
        }
    }
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        long long ans=0x15f;
        for(auto &a:edge[x]){
            for(auto &b:edge[y]){
                if(a.second==b.second){
                    int temp=w[x]+w[y]+a.first+b.first;
                    ans=min(ans,(long long)temp);
                }
            }
        }
        cout<<ans;
    }
}
