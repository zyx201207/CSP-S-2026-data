#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int dd=1e5;
int ans[dd];
int step=0;
int minn=1e18;
int n;
struct node{
    int a,t;
};
bool cmp(node a,node b){
    return a.a<b.a;
}
/*int findd(int x,int y,vector<int>w,vector<vector<node>>way,vector<int>wayn,vector<vector<int>>point){
    if(x==y)return minn;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=wayn[i];j++){
            step++;
            if(ans[step]>minn)continue;
            ans[step]=min(minn,ans[step-1]+way[i][y].t);
            return findd(way[i][j].a,y)+ans[step];
        }
    }
}*/
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int>w(m+1);/*
    vector<vector<node>>way(n+1,vector<node>(5e5+5));
    vector<int>wayn(n+1);
    vector<vector<int>>point(m);*/
    for(int i=1;i<=m;i++)cin>>w[i];
    /*for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        wayn[i]=a;
        vector<node>test(a);
        for(int j=1;j<=a;j++){
            cin>>test[j-1].a>>test[j-1].t;
        }
        sort(test.begin(),test.end(),cmp);
        for(int j=1;j<=a;j++){
            way[i][j].a=test[j-1].a;
            way[i][j].t=test[j-1].t;
            point[way[i][j].a].push_back(j);
        }
    }*/
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i=0;i<1e5;i++)ans[i]=1e18;
        step=0;
        minn=0;
            cout<<w[x]+w[y]+11<<' ';

        cout<<'\n';
    }
    return 0;
}
