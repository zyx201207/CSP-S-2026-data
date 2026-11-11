#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
ll w[N],k[N],a[N][N],t[N][N],tu[N][N];
ll mp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mp[i][j]=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            mp[i][a[i][j]]=j;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            tu[i][j]=2e9+5;
            for(int l=1;l<=k[i];l++){
                for(int r=1;r<=k[j];r++){
                    if(a[i][l]==a[j][r]){
                        if(t[i][l]+t[j][r]<tu[i][j])tu[i][j]=t[i][l]+t[j][r];
                    }
                }
            }
        }
    }
    while(q--){
        ll x,y,minn=1e10+5;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            int sum=w[x]+w[y]+t[i][mp[i][x]];
            if(mp[i][x]){
                if(mp[i][y])minn=min(minn,sum+t[i][mp[i][y]]);
                for(int j=1;j<=n;j++){
                    if(i==j)continue;
                    if(mp[j][y])minn=min(minn,sum+tu[i][j]+t[j][mp[j][y]]);
                    for(int s=1;s<=n;s++){
                        if(s==j||s==i)continue;
                        if(mp[s][y])minn=min(minn,sum+tu[i][j]+tu[j][s]+t[s][mp[s][y]]);
                    }
                }
            }
        }
        cout<<minn<<endl;
    }
    return 0;
}
