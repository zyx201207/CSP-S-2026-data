#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={},x[300005]={};scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        int b[500005]={},r(0);
        int pos[300005]={};
        for(int j=i;j<=n;j++){
            if(pos[a[j]]){
                for(int k=pos[a[j]]+1;k<=r;k++)pos[b[k]]=0;
                r=pos[a[j]];
            }
            else{
                b[++r]=a[j];
            }
        }x[r]++;
    }for(int i=0;i<m;i++)printf("%d",x[i]);
    return 0;
}
