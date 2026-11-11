#include<bits/stdc++.h>
using namespace std;
int n,m,a[555555],f[555555],sum=0,id[333333],ans[333333];
bool b[333333];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    memset(b,false,sizeof(b));
    memset(id,0,sizeof(id));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        memset(b,false,sizeof(b));
        memset(id,0,sizeof(id));
        sum=0;
        for(int j=i;j<=n;j++){
            f[++sum]=a[j];
            if(b[a[j]] && id[a[j]]<=sum){
                for(int k=sum-1;k>id[a[j]];k--)
                    b[f[k]]=false;
                sum=id[a[j]];
            }
            else{
                b[a[j]]=true;
                id[a[j]]=sum;
            }
        }
        for(int j=1;j<=sum;j++){
            ans[f[j]]++;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
}
