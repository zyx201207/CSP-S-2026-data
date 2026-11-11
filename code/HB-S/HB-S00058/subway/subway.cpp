#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tmpx,tmpy,x[100005],y[100005];
long long ans,tmpcnt;
int w[500005],k[505];
vector<int> a[505],t[505];
vector<pair<int,int>> s[500005];
void dfs(int start,int e,long long cnt){
    if(start==e){
        tmpcnt=min(tmpcnt,cnt);
        return ;
    }
    for(auto &tmptmptmp:s[start]){
        int i=tmptmptmp.first,j=tmptmptmp.second;
        for(int b=j;(b<k[i])&&(a[i][b]<=e);b++){
            dfs(a[i][b+1]+1,e,cnt+t[i][j-1]+t[i][b]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>tmpx>>tmpy;
            a[i].push_back(tmpx);
            t[i].push_back(tmpy);
            s[tmpx].push_back({i,j});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        tmpcnt=LLONG_MAX;
        dfs(x[i],y[i],0);
        ans=w[x[i]]+tmpcnt+w[y[i]];
        cout<<ans<<'\n';
    }
    return 0;
}
