#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int c[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            int f=0,s=0;
            for(int k=1;k<=cnt;k++){
                if(b[k]==a[j]){
                    f=1;
                    s=k;
                }
            }
            if(f==0){
                b[++cnt]=a[j];
            }else{
                for(int o=s;o<=cnt;o++){
                    b[o]=0;
                }
                cnt=s;
                b[cnt]=a[j];
            }
        }
        for(int p=1;p<=cnt;p++){
            for(int q=1;q<=m;q++){
                if(b[p]==q)
                    c[q]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",c[i]);
    return 0;
}
