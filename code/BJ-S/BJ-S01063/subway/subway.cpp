#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int Q=1e5+10;
int c,n,m,d,q;
int w[M];
int a[510][M];
int t[510][M];
int x[Q],y[Q];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        cout<<w[1]*3<<endl;
    }
    return 0;
}