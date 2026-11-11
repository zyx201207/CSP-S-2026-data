#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
struct walengthy{
    long long to,l;

};
long long n,c,m,d,q,w[MAXM],k[505],a[505][MAXM],t[505][MAXM],dis[505][505];
vector<int> s[MAXM];
vector<walengthy> walength[505];
void BFS(int n1){
    queue<int> que;
    que.push(n1);
    while(!que.empty()){
        int no=que.front();
        que.pop();
        for(int i=0;i<walength[no].size();i++){
            if(dis[n1][walength[no][i].to]>dis[n1][no]+walength[no][i].l||dis[n1][walength[no][i].to]==0){
                que.push(walength[no][i].to);
                dis[n1][walength[no][i].to]=dis[n1][no]+walength[no][i].l;
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>a[i][j]>>t[i][j];
            s[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(s[i].size()>1){
            for(int k=0;k<s[i].size();k++){
                for(int j=k+1;j<s[i].size();j++){
                    long long ll=t[s[i][k]][i]+t[s[i][j]][i];
                    walength[k].push_back({j,ll});
                    walength[j].push_back({k,ll});
                }
            }
        }
    }
    while(q--){
        long long x,y,ans=11451419198,sta1,sta2;
        cin>>x>>y;
        for(int i=0;i<s[x].size();i++){
            for(int j=0;j<s[y].size();j++){
                if(!dis[s[x][i]][s[y][j]]&&s[x][i]!=s[y][j]){
                    BFS(s[x][i]);
                }
                if(dis[s[x][i]][s[y][j]]<ans){
                    ans=dis[s[x][i]][s[y][j]];
                    sta1=s[x][i];sta2=s[y][j];
                }
            }
        }
        ans+=w[x]+w[y];
        ans+=t[sta1][x]+t[sta2][y];
        cout<<ans<<'\n';
    }
    return 0;
}
