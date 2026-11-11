#include<bits/stdc++.h>
using namespace std;
int w[500005],f[10005][10005];
int c,n,m,d,q,k;
int main(){
    freopen("subway.in","r",stdin);    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)cin>>w[i];

    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            f[i][a]=t+w[a];
            f[a][i]=t+w[i];
        }

    }

    for(int i=1;i<=m;i++){
        f[i][i]=w[i];
    }  
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]+w[k]+w[j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        printf("%d\n",f[s][e]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}