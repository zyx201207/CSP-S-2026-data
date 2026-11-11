#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[300010];
int c[500010];
int d[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[j]=0;
        }
        for(int j=1;j<=n;j++){
            c[j]=0;
        }
        l=0;
        for(int j=i;j<=n;j++){
            if(d[a[j]]!=0){
                for(int z=d[a[j]]+1;z<=l;z++){
                    d[c[z]]=0;
                }
                l=d[a[j]];
            }else{
                l++;
                c[l]=a[j];
                d[a[j]]=l;
            }
        }
        for(int j=1;j<=l;j++){
            b[c[j]]++;
        }
    }
    for(int j=1;j<=m;j++){
        printf("%d ",b[j]);
    }
}
