#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXNm 625001
#define MAXNn 601
int c,n,m,d,q,road[MAXNn][MAXNm];
ll w[MAXNm],ans=0,sum=0;
ll dfs(int u,int x,int y){
    if(u==y)
        ans=min(ans,sum);
    
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> road[i][1];
        for(int j = 2;j <= 2*road[i][1]+1;j++)
            cin >> road[i][j];
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        sum+=w[x];
        sum+=w[y];
        
    }
    return 0;
}