#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[200005],c[500005],d[200005],p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);p+=(a[i]<a[i-1]);}
    if(!p){
        for(int i=1;i<=n;i++)d[a[i]]=i;
        for(int i=1;i<=m;i++)printf("%d ",d[i]);
        return 0;
    }for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(int j=n;j>=i;j--){
            if(!b[a[j]])++d[a[j]];
            else{
                for(int k=j;k<b[a[j]];k++)b[a[k]]=0;;
            }
            b[a[j]]=j;
        }
    }
    //for(int i=1;i<=n;i++)d[a[i]]+=c[i];
    for(int i=1;i<=m;i++){printf("%d ",d[i]);}
    return 0;
}
