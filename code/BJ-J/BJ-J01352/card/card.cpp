#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,m,i,j,k,l;
    scanf("%d %d",&n,&m);
    int a[n+1],b[2*n+1],ans[n+1];
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans[i]=0;
    }
    for(i=1;i<=2*n;i++){
        b[i]=0;
    }
    for(i=1;i<=n;i++){
            int t=1;
        for(j=i;j<=n;j++){

            for(k=1;k<=t;k++){
                if(b[k]==a[j]){
                   b[k]=-1;
                }
            }
            b[t]=a[j];
            t++;
        }
        int c[m+1];
        for(j=1;j<=t;j++){
            c[b[j]]=1;
        }
        for(j=1;j<=t;j++){
            ans[j]+=c[j];
        }
    }
    for(j=1;j<=m;j++){
            printf("%d",ans[i]);
        }
    return 0;
}
