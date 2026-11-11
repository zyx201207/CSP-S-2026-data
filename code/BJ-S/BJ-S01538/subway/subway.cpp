#include<bits/stdc++.h>
#define INF 1e15
using namespace std;
long long w[500005],t[500005][25],x[500005][25];
int A,k;
long long a[505][505];
int C,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a[i][j]=INF;
    }
    for(int i=1;i<=n;i++) a[i][i]=0;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>A;
            t[A][0]++;
            x[A][t[A][0]]=i;
            cin>>t[A][t[A][0]];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<t[i][0];j++){
                a[x[i][j]][x[i][j+1]]=min(a[x[i][j]][x[i][j+1]],t[i][j]+t[i][j+1]);
                a[x[i][j+1]][x[i][j]]=min(a[x[i][j+1]][x[i][j]],t[i][j+1]+t[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++) a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
        }
    }
    long long X,Y,ans;
    while(q--){
        cin>>X>>Y;
        ans=INF;
        for(int i=1;i<=t[X][0];i++){
            for(int j=1;j<=t[Y][0];j++){
                ans=min(ans,t[X][i]+t[Y][j]+a[x[X][i]][x[Y][j]]);
            }
        }
        cout<<ans+w[X]+w[Y]<<endl;
    }
    return 0;
}
