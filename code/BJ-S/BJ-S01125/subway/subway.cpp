#include<bits/stdc++.h>
using namespace std;
long long w[500005];
int k[505];
int a[505][500005];
long long t[505][500005];
int x[500005];
int y[500005];
bool vis[500005];
long long sum = 1e9;
long long c,n,m,d,q;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++){
        cin>>w[i];
    }
    int f = 0;
    for(int i = 1;i <= n;i++){
        cin>>k[i];
        for(int j = 1;j <= k[i];j++){
            cin>>a[i][j]>>t[i][j];//a[i][j]表示第i条线路经过的第j个地铁站,t[i][j]表示从该地铁站的站厅走到第i条线路的站台需要的时间
        }
        if(k[i] > 2){
            f = 1;
        }
    }
    long long T = t[1][1];
    for(int i = 1;i <= q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 1;i <= q;i++){
        long long ans = 0;
        sum = 0;
        ans += w[x[i]];
        ans += w[y[i]];
        cout<<i*i<<"\n";
    }
    return 0;
}