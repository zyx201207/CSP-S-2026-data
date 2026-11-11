#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[200005],a[1005][1005],t[1005][1005],x[200005],y[100005],mp[1005][1005],T;
int add(int x,int y){
    mp[x][y]=1;
    mp[y][x]=1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(mp,7788,sizeof(mp));
    for(int i=1;i<=m;i++){
        mp[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            T=t[i][j];
            if(j!=1) add(a[i][j],a[i][j-1]);
        }
    }
    int sum=0;
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        sum+=2*T;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
