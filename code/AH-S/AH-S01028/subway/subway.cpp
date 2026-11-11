#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int c,n,m,d,q;
long long w[500002];
int b[500002][22];
long long l[500002][22];
long long edge[502][502];
long long f[502][502];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int clr=1;clr<=n;clr++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            long long id,t;
            scanf("%lld%lld",&id,&t);
            b[id][++b[id][0]]=clr;
            l[id][b[id][0]]=t;
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i][0]>1){
            for(int j1=1;j1<=b[i][0];j1++){
                for(int j2=j1+1;j2<=b[i][0];j2++){
                    int c1=b[i][j1];
                    int c2=b[i][j2];
                    if(edge[c1][c2]>0){
                        edge[c1][c2]=min(edge[c1][c2],l[i][j1]+l[i][j2]);
                    }else{
                        edge[c1][c2]=l[i][j1]+l[i][j2];
                    }
                    edge[c2][c1]=edge[c1][c2];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(edge[i][j]!=0){
                f[i][j]=edge[i][j];
                f[j][i]=edge[i][j];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]!=0&&f[k][j]!=0){
                    if(f[i][j]!=0)
                        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                    else f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int a1,b1;
        cin>>a1>>b1;
        long long ans=-1;
        for(int j1=1;j1<=b[a1][0];j1++){
            for(int j2=1;j2<=b[b1][0];j2++){
                int c1=b[a1][j1];
                int c2=b[b1][j2];
                if(c1==c2){
                    ans=l[a1][j1]+l[b1][j2];
                    continue;
                }
                if(f[c1][c2]==0) continue;
                if(ans==-1){
                    ans=f[c1][c2]+l[a1][j1]+l[b1][j2];
                }else{
                    ans=min(ans,f[c1][c2]+l[a1][j1]+l[b1][j2]);
                }
            }
        }
        cout<<ans+w[a1]+w[b1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
