#include<bits/stdc++.h>
using namespace std;

int a[500005];
vector <int> e[500005];
long long p[500005][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;//n条线，m个站
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        int k; cin >> k;
        for(int j=1;j<=k;j++){
            int x; cin >> x;
            e[x].push_back(i);
            cin >> p[x][i];
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;
        cin >> s >> t;
        int j,k;
        bool zh=0;
        for(j=1;j<=e[s].size();j++){
            for(k=1;k<=e[t].size();k++){
                if(e[s][j]==e[t][k]){
                    zh=1;
                    break;
                }
            }
            if(zh==1) break;
        }
        int ans=a[s]+a[t]+p[s][e[s][j]]+p[t][e[t][k]];
        cout << ans << endl;
    }
    return 0;
}
