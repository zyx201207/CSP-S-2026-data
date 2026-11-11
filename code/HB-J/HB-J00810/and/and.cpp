#include<bits/stdc++.h>
using namespace std;
const int MAXN=20005;
int f[MAXN][MAXN],a[MAXN],n,m,ans=0;
int main(){
    freopen("and.in","r",stdin);   freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans=max(a[i],ans);
        f[i][0]=ans;
        //ans=max(a[i],ans);
    }
    //for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            f[i][j]=max(f[i-1][j],(f[i-1][j-1]&a[i]));
            //printf("%d ",f[i][j]);
        }
         //printf("\n");
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             printf("%d ",f[i][j]);
        }
        printf("\n");
    }
    printf("%d",f[n][m]);
}