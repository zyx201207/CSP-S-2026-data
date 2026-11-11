#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N],ans[N];
bool b[N];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        memset(c,0,sizeof(c));
        memset(b,false,sizeof(b));
        for(int j=i;j<=n;j++){
            if(!b[a[j]]){
                c[++cnt]=a[j];
                b[a[j]]=true;
            }else{
                for(int k=1;k<=cnt;k++){
                    if(c[k]==a[j]){
                        cnt=k-1;
                        break;
                    }
                }
                c[++cnt]=a[j];
                b[a[j]]=true;
            }
        }
        for(int j=1;j<=cnt;j++){
            ans[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}
