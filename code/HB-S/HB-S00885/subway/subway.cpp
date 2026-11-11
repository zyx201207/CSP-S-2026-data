#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,a[N][505],t[1000],mp[500][500],ans;
vector<long long>st[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long x,y;
            cin>>x>>y;
            a[i][x]=y;
            st[x].push_back(i);

        }
    }
    memset(mp,0x3f,sizeof mp);
    for(int i=1;i<=m;i++){
        mp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            for(int k=1;k<=n;k++){
                if(a[i][k]&&a[j][k]){
                    mp[j][i]=mp[i][j]=min(mp[i][j],a[i][k]+a[j][k]);
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i!=j&&i!=k&&j!=k){
                    mp[j][i]=mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
            }
        }
    }
    while(q--){
        long long x,y,ans=1e18;
        cin>>x>>y;
        for(int i=0;i<st[x].size();i++){
            for(int j=0;j<st[y].size();j++){
                ans=min(ans,mp[st[x][i]][st[y][j]]+a[st[x][i]][x]+a[st[y][j]][y]);
            }
        }
        cout<<ans+t[x]+t[y]<<endl;
    }
    return 0;
}

