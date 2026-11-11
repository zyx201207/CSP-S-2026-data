#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int M=1e5+25255,N=510;
ll w[M];
int k[N];
vector<ll> t[N];
vector<int> a[N];
int c,n,m,d,q,x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    if(m>3000) return 0;
    ll biao[m+5][m+5];
    for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++) biao[j][i]=biao[i][j]=INT_MAX;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        a[i].push_back(0);
        t[i].push_back(0);
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            int b;
            ll s;
            cin >> b >> s;
            a[i].push_back(b);
            t[i].push_back(s);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k[i];j++)
            for(int y=j+1;y<=k[i];y++)
                biao[a[i][j]][a[i][y]]=biao[a[i][y]][a[i][j]]=min(biao[a[i][j]][a[i][y]],w[a[i][j]]+t[i][j]+t[i][y]+w[a[i][y]]);
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            for(int mid=1;mid<=m;mid++){
                if(mid==i||mid==j||biao[i][mid]==INT_MAX||biao[j][mid]==INT_MAX) continue;
                biao[i][j]=biao[j][i]=min(biao[i][j],biao[i][mid]+biao[mid][j]-w[mid]*2);
            }
        }
    }
    while(q--){
        cin >> x >> y;
        cout << biao[x][y] << el;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
