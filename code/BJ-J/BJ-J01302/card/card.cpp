#include<bits/stdc++.h>
using namespace std;
int lst[300010],rst[300010],a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //freopen("kard.in","r",stdin);
    //freopen("kards.in","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1,r;i<=n;++i){
        scanf("%d",&r);
        lst[r]=i;
        if(rst[r]==0)rst[r]=i;
        a[i]=r;
    }if(n<=500){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++i){
                for(int k=j;k<=n;++k){

                }
            }
        }
    }if(m<=2){
        for(int i=1;i<=2;++i){
            int h=0,r=0;
            if(a[n]==i)r=n;
            else for(int j=n;j>=1;--j){
                if(j>=rst[0]&&a[j]==1){
                    h=1;
                }if(a[j]==i||)++r;
            }
        }
    }
    for(int i=1;i<=m;++i){
        if(rst[i]!=0)printf("%d ",n-rst[i]+1);
        else printf("0\n");
    }return 0;
}