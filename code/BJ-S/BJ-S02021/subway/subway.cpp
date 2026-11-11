#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,p;
    queue<long long>q;
    cin>>c>>n>>m>>d>>p;
    long long w[500005];
    long long l[5005][5005]={},t[5005][5005];
    for(int i=1;i<=m;i++){
        cout<<w[i];
    }
    int maxs=0;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        maxs=max(maxs,k);
        for(int j=1;j<=k;j++){
            cin>>l[i][j];
            cin>>t[i][j];
        }
    }

    for(int i=1;i<=p;i++){
        int x,y;
    cin>>x>>y;
    for(int i=1;i<=maxs;i++){
        for(int j=i;j<=maxs;j++){
            if(l[1][i]==l[2][j]){
                q.push(l[1][i]);
            }
        }
    }
    long long ans=1e9;
        while(!q.empty()){
            long long f=q.back();
            q.pop();
            long long maxx=0;
            maxx+=w[x]+t[1][x]+t[1][f]+t[2][f]+t[2][y]+w[y];
            ans=min(maxx,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
