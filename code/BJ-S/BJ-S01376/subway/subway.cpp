#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int D[20001][20001];
int w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        for(int j=1;j<=m;j++){
            if(i==j){
                D[i][j]=0;
            }else{
                D[i][j]=100000000;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a[505];
        int t[505];
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
                    for(int u=1;u<=j;u++){
                        if(D[a[u]][a[j]]>t[j]+t[u]){
                        D[a[u]][a[j]]=t[j]+t[u];
                    }
                    if(D[a[j]][a[u]]>t[j]+t[u]){
                        D[a[j]][a[u]]=t[j]+t[u];
                    }
                }
        }
    }
    for(int mid=1;mid<=m;mid++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                    long long x=D[i][mid]+D[mid][j];
                if(x<D[i][j]) D[i][j]=x;
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<D[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
