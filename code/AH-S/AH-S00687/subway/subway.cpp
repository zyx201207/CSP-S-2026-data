#include<bits/stdc++.h>
using namespace std;
int c,m,d,q,n,w[500005],q[505],cnt[500005],id[500005],cnt2[500005];
long long ans;
struct stop{
    int t,a;
}p[505][25];
struct Map{
    int to,v,idd;
};
vector<Map> ma[500005];
void dfs(int s,int va){
    for(int i=1;i<=cnt[s];i++){

        dfs(ma[s][i].to,va+);
    }
}
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>q[i];
        for(int j=1;j<=q[i];j++){
            cin>>p[i][j].a>>p[i][j].t;
            if(id[p[i][j].a]!=0){
                id[p[i][j]].push_back(i);
                cnt2[p[i][j].a]++;
            }
            p[i][j].t+=w[p[i][j].a];
            if(j!=1){
                ma[p[i][j-1].a].push_back({p[i][j].a,p[i][j-1].t,i});
                ma[p[i][j].a].push_back({p[i][j-1].a,p[i][j].t,i});
                cnt[p[i][j-1].a]++;
                cnt[p[i][j].a]++;
            }
        }
    }
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=w[x]+w[y];
        dfs(x,0,);
    }
	return 0;
}
//准备退役了
