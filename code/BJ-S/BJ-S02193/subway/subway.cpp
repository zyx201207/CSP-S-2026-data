#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,num[100010],b[1001][1001],e[100010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> num[i];
    }

    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        for(int j=1;j<=t;j++){
            int x,y;
            b[i][j]=0;
            b[j][i]=0;
            cin >> x >> y;
            if(e[x]==0){
                e[x]+=y;
            }
            else{
                b[i][x]+=e[x];
            }
        }

    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                b[i][j]=max(b[i][j],b[i][k]+b[k][j]);
            }
        }
    }
    while(q--){
        long long r,c;
        cin >> r >> c;
        cout << b[r][c]+num[r]+num[c] << '\n';
    }
    return 0;
}