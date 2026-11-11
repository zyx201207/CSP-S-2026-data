#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+1],a[n+1][m+1],k[n+1],t[n+1][m+1];
    vector<int> hc[m+1];
    long long mapp[m+1][m+1]={};
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) mapp[i][j]=1e17;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(j==2) mapp[a[i][j]][a[i][j-1]]=mapp[a[i][j-1]][a[i][j]]=0;
            hc[a[i][j]].push_back(i);
            for(int k2:hc[a[i][j]]) for(int k3=1;k3<=2;k3++) mapp[a[i][j]][a[k2][k3]]=mapp[a[k2][k3]][a[i][j]]=t[i][j];
        }
    }
    while(q--){
        int x,y;
        long long ans=0;
        cin>>x>>y;
        ans+=w[x]+w[y];
        cout<<mapp[x][y]+ans<<endl;
    }
    return 0;
}
