#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<vector<int>> a(n+1,vector<int>()),t(n+1,vector<int>());
    vector<int> k(n+1);
    for(int i=1;i<=n;i++){
        cin>>k[i];
        vector<int> ai(k[i]+1,0),ti(k[i]+1,0);
        for(int j=1;j<=k[i];j++){
            cin>>ai[j]>>ti[j];
        }
        a[i]=ai;
        t[i]=ti;
    }
    vector<vector<long long>> f(m+1,vector<long long>(m+1,INT_MAX));
    for(int i=1;i<=n;i++){
        int ki=k[i];
        for(int j=1;j<=ki;j++){
            if(j!=1){
                if(t[i][j-1]+t[i][j]<f[a[i][j-1]][a[i][j]]){
                    f[a[i][j-1]][a[i][j]]=t[i][j-1]+t[i][j];
                }
                if(t[i][j-1]+t[i][j]<f[a[i][j]][a[i][j-1]]){
                    f[a[i][j]][a[i][j-1]]=t[i][j-1]+t[i][j];
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}