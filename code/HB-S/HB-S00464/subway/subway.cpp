#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define int128 __int128
#define Tianyi 712

inline void fileio(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}

const int N=2012.712;
int c,n,m,d,q;
int w[N],k[N];
vector<pair<int,int>> sta[N];
vector<pair<int,int>> g[N];
int g1[N][N];
int64 ans;

bool judge(int a,int b){//<
    if(a==-1){
        return 0;
    }if(b==-1){
        return 1;
    }return a<b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fileio();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int ai,ti;
            cin>>ai>>ti;
            sta[ai].push_back(make_pair(i,ti));
        }
    }
    //sta[i]: di i zhan de di tie xu hao
    // jian tu
    // cerr<<"---";
    for(int i=1;i<=n;i++){
        int len=sta[i].size();
        for(int j=1;j<len;j++){
            for(int k=0;k<j;k++){
                // cerr<<sta[i][j].first<<" "
                //     <<sta[i][k].first<<" "
                //     <<sta[i][j].second<<" "
                //     <<sta[i][k].second
                //     <<endl;
                g[sta[i][j].first].push_back(
                    make_pair(sta[i][k].first,
                    sta[i][j].second+sta[i][k].second
                    ));
                g[sta[i][k].first].push_back(
                    make_pair(sta[i][j].first,
                    sta[i][j].second+sta[i][k].second
                    ));
            }
        }
    }
    // cerr<<"---";
    memset(g1,-1,sizeof(g1));
    for(int i=1;i<=n;i++){
        g1[i][i]=0;
    }for(int i=1;i<=n;i++){
        for(auto tmp:g[i]){
            int t1=tmp.first,t2=tmp.second;
            if(g1[i][t1]==-1){
                g1[i][t1]=t2;
            }else{
                g1[i][t1]=min(g1[i][t1],t2);
            }
        }
    }

    //debug
    // for(int i=1;i<=n;i++){
    //     for(auto tmp:g[i]){
    //         cout<<tmp.first<<" ";
    //     }
    //     cout<<"\n";
    // }cout<<"\n";0 2 5 20 2
    

    //floyd
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(g1[i][k]==-1 || g1[k][j]==-1){
                    continue;
                }
                if(g1[i][j]==-1){
                    g1[i][j]=g1[i][k]+g1[k][j];
                }
                g1[i][j]=min(g1[i][j],g1[i][k]+g1[k][j]);
            }
        }
    }

    //debug
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<g1[i][j]<<" ";
    //     }cout<<"\n";
    // }

    while(q--){
        int _start_station,_end_station,_start,_end;
        cin>>_start_station>>_end_station;
        _start=sta[_start_station][0].first;
        _end=sta[_end_station][0].first;
        int _ans=w[_start_station]+w[_end_station]
            +sta[_start_station][0].second
            +sta[_end_station][0].second
            +g1[_start][_end];
        cout<<_ans<<"\n";

        // cout<<g1[_start][_end]<<"\n";
    }
    //rp++
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/