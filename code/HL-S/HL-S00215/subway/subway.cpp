#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],g[510][510],a[510][2],b[510][2],kc[510];
void solve1_6(){
    cin>>n>>m>>d>>q;
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            g[i][j]=1e18;
            g[j][i]=1e18;
            if(i==j){
                g[i][j]=0;
                g[j][i]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long x,t;
            cin>>x>>t;
            g[m+i][x]=min(g[m+i][x],t);
            g[x][m+i]=min(g[x][m+i],t);
        }
    }
    for(int k=1;k<=n+m;k++){
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                if(g[i][k]!=1e18&&g[k][j]!=1e18)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+g[x][y]<<"\n";
    }
}
void solve7_8(){
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=1e18;
            g[j][i]=1e18;
            if(i==j){
                g[i][j]=0;
                g[j][i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        long long k;
        cin>>kc[i];
        long long x,t;
        cin>>x>>t;
        a[i][0]=x;
        b[i][0]=t;
        if(k>1){
            cin>>x>>t;
            a[i][1]=x;
            b[i][1]=t;
            if(a[i][0]>a[i][1]){
                    swap(a[i][0],a[i][1]);
                    swap(b[i][0],b[i][1]);
            }
        }

    }
    for(int i=1;i<=n;i++){
        if(kc[i]==1){
            continue;
        }
        for(int j=i+1;j<=n;j++){
            if(kc[j]==1){
                continue;
            }
            if(a[i][0]==a[j][0]&&a[i][1]==a[j][1]){
                continue;
            }
            if(a[i][0]==a[j][0]){
                g[i][j]=b[i][0]+b[j][0];
                g[j][i]=g[i][j];
            }
            if(a[i][0]==a[j][1]){
                g[i][j]=b[i][0]+b[j][1];
                g[j][i]=g[i][j];
            }
            if(a[i][1]==a[j][0]){
                g[i][j]=b[i][1]+b[j][0];
                g[j][i]=g[i][j];
            }
            if(a[i][1]==a[j][1]){
                g[i][j]=b[i][1]+b[j][1];
                g[j][i]=g[i][j];
            }
        }
    }
    for(int k=1;k<=n;k++){
        if(kc[k]==1){
            continue;
        }
        for(int i=1;i<=n;i++){
            if(kc[i]==1){
                continue;
            }
            for(int j=1;j<=n;j++){
                if(kc[j]==1){
                    continue;
                }
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        long long res=1e18;
        for(int i=1;i<=n;i++){
            if(kc[i]==1){
                continue;
            }
            for(int j=i+1;j<=n;j++){
                if(kc[j]==1){
                    continue;
                }
                if((a[i][0]==x||a[i][1]==x)&&(a[j][0]==y||a[j][1]==y)){
                    res=min(res,g[i][j]);
                }
                if((a[j][0]==x||a[j][1]==x)&&(a[i][0]==y||a[i][1]==y)){
                    res=min(res,g[j][i]);
                }
            }
        }
        cout<<w[x]+w[y]+res<<"\n";
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>c;
    solve1_6();
	return 0;
}

