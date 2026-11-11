#include<bits/stdc++.h>
using namespace std;
int c,t,n,q;
long long x[2000005],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int o=1;o<=t;o++){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        if(c==11||c==12){
            if(d>=x[3]-x[1]&&d<x[4]-x[1]){
                printf("%d\n",n-3);
            }else{
                printf("0\n");
            }
        }else{
            q=n;
            for(int i=1;i<=n;i++){
                if(x[i]-x[1]>d){
                    q=i-1;
                    break;
                }
            }
            printf("%d\n",0);
        }
    }
}
