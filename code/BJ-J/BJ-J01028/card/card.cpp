#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int a[N],bef[N],t[N],ans[N],n,m;
int main(){
    freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!bef[a[j]]) bef[a[j]]=j;
            else{
                t[bef[a[j]]]-=1;
                t[j]+=1;
                //printf("%d : %d : [ %d , %d ] \n",i,j,bef[a[j]],j);
                bef[a[j]]=j;
            }
        }
        //for(int j=1;j<=n;j++) printf("%d ",t[j]);
        //printf("\n");
        int sum=0;
        for(int j=i;j<=n;j++){
            sum+=t[j];
            if(sum==0){
                ans[a[j]]++;
                //printf("%d %d\n",j,ans[a[j]]);
            }
            bef[j]=t[j]=0;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
