#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],minn,sub[500005],x,y;
//queue<int,vector<int>> q;
struct kat{
    long long a,t;
}kt[505][100005];
void dfs(long long x,long long y,long long sum){
    //sum+=
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>sub[i];
        for(long long j=1;j<=sub[i];j++){
            cin>>kt[i][j].a>>kt[i][j].t;
           //q[kt[i][j-1].a].push(kt[i][j].a);
        }
    }
    for(long long i=1;i<=q;i++){
        cin>>x>>y;
        minn=LLONG_MAX;
        long long sum=0;
       //dfs(x,y,sum);
        cout<<minn+w[x]+w[y]<<"\n";
    }
    return 0;
}//heart broken TT QWQ qwq lai nian zai zhan ba !
