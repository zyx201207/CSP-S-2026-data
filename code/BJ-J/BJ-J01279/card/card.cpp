#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],n,m,cnt;
int main(){
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);

    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            b[a[j]]++;
            if(b[a[j]] > 1){
                for(int k = 1;k <= m;k++){
                    b[k] = 0;
                    
                }
                
            }
        }
        for(int j = 1;j <= m;j++){
            c[j] += b[j];
        }
    }
    for(int i = 1;i <= m;i++){
        
        if(i != m){
            printf("%d ",c[i]);
        }else{
            printf("%d",c[i]);
        }
    }
    return 0;
}