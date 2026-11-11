#include<bits/stdc++.h>
#define int long long
using namespace std;
struct station{
    vector<int> line;
    vector<int> time;
    int w;
};
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<station> s(m+5);
    for(int i=0;i<m;i++){
        cin>>s[i].w;
    }
    int time[505][505];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                time[i][j]=0;
            }else{
               time[i][j]=1e15;
            }
        }
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            a--;
            s[a].line.push_back(i);
            s[a].time.push_back(t);
            for(int k=0;k<s[a].line.size()-1;k++){
                time[i][s[a].line[k]]=min(time[i][s[a].line[k]],t+s[a].time[k]);
                time[s[a].line[k]][i]=time[i][s[a].line[k]];
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==i||k==j||i==j){
                    continue;
                }
                time[i][j]=min(time[i][j],time[i][k]+time[k][j]);
                time[j][i]=time[i][j];
            }
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        int minn=1e18;
        for(int i=0;i<s[x].line.size();i++){
            for(int j=0;j<s[y].line.size();j++){
                minn=min(minn,time[s[x].line[i]][s[y].line[j]]+s[x].time[i]+s[y].time[j]);
            }
        }
        cout<<minn+s[x].w+s[y].w<<'\n';
    }
    return 0;
}
