#include <bits/stdc++.h>
using namespace std;
const int MMax = 509;
int C,N,M,D,Q;
long long W[MMax];
long long SS[1039][1039];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>C>>N>>M>>D>>Q;
    for(int i=1;i<=M;i++){
        cin >> W[i];
    }
    memset(SS,0x3f,sizeof(SS));
    for(int i=1;i<=N;i++){
        int K;
        cin >> K;
        for(int j=1;j<=K;j++){
            int a,t;
            cin>>a>>t;
            SS[a][509+i] = t;
            SS[509+i][a] = t;
        }
    }
    for(int i=1;i<=509+N;i++){
        SS[i][i] = 0;
    }
    for(int k=1;k<=509+N;k++){
        for(int i=1;i<=509+N;i++){
            for(int j=1;j<=509+N;j++){
                SS[i][j] = min(SS[i][j],SS[i][k]+SS[k][j]);
            }
        }
    }
    long long ans = 0;
    for(int i=1;i<=Q;i++){
        int u,v;
        cin >> u >> v;
        ans = W[u]+W[v];
        ans+=SS[u][v];
        cout << ans<<"\n";
    }
    return 0;
}
