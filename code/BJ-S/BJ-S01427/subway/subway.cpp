#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll s[5005][5005];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll c, n, m, d, q;
    cin>>c>>n>>m>>d>>q;
    ll a[5005];
    for(ll i=1;i<=m;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        ll rw[5005][2];
        for(int j=1;j<=k;j++){
            cin>>rw[j][0]>>rw[j][1];
            for(int k=1;k<j;k++){
                s[rw[j][0]][rw[k][0]] = min(s[rw[j][0]][rw[k][0]], rw[j][1] + rw[k][1]);
                if(s[rw[j][0]][rw[k][0]] == 0){
                    s[rw[j][0]][rw[k][0]] = rw[j][1] + rw[k][1];
                }
                s[rw[k][0]][rw[j][0]] = min(s[rw[k][0]][rw[j][0]], rw[j][1] + rw[k][1]);
                if(s[rw[k][0]][rw[j][0]] == 0){
                    s[rw[k][0]][rw[j][0]] = rw[j][1] + rw[k][1];
                }
            }
        }
    }
    bool f = false;
    while(!f){
        f = true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    if(k != i && k != j && s[i][k] != 0 && s[k][j] != 0){
                        if(s[i][j] == 0){
                            s[i][j] = s[i][k] + s[k][j];
                        }
                        else{
                            s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
                        }
                    }
                }
                if(s[i][j] == 0){
                    f = false;
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int st, e;
        cin>>st>>e;
        int ans = a[st] + a[e] + s[st][e];
        cout<<ans<<endl;
    }
    return 0;
}
