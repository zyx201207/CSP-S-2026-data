#include<bits/stdc++.h>
using namespace std;
long long c,n,m,b,d,q,k[500010],mp[501][50010],t[501][50010],w[500010],x,sum,y,both[50010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>mp[i][j]>>t[i][j];
            both[mp[i][j]]++;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        sum=w[x]+w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(mp[i][j]==x)sum+=t[i][j];
                if(mp[i][j]==y)sum+=t[i][j];
                if(both[mp[i][j]]>1)sum+=t[i][j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}