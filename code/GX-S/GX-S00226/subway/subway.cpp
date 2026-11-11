#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005], a[505][20005],t[505][20005],x[20005],y[20005],mp[20005][20005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(mp,100000000,sizeof(mp));
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i++) cin>>w[i];
    for(int i = 1; i <= n; i++){
        int k;
        cin>>k;
        cin>>a[i][1]>>t[i][1]>>a[i][2]>>t[i][2];
        mp[a[i][1]][mp[i][2]]=w[i];
        for(int j = 3; j <= 2*k; j++){
            cin>>a[i][j]>>t[i][j];
            mp[a[i][j]][mp[i][j-1]]=w[i];
            mp[a[i][j]][mp[i][j+1]]=w[i];
        }
        mp[a[i][2*k]][mp[i][2*k+1]]=100000000;
    }
    for(int i = 1; i <= q; i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j= 1; j <= m; j++){
            cout<<mp[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i = 1; i <= m; i++){
        for(int j= 1; j <= m; j++){
            for(int k = 1; k <= m; k++){
                mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
            }
        }
    }
    long long sum=0;
    for(int i = 1; i <= q; i++){
        sum+=mp[x[i]][y[i]];
        sum+=w[x[i]]+w[y[i]];
        cout<<sum<<endl;
    }
    return 0;
}
