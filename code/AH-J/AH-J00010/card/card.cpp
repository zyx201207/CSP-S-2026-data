#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[500005],a[500005],t[500005];
bool f[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(!t[a[j]]){
                t[a[j]]=j;
            }else{
                for(int k=t[a[j]];k<j;k++){
                    f[k]=1;
                    t[a[k]]=0;
                }
                t[a[j]]=j;
            }
        }
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            if(!f[j]){
                t[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            ans[j]+=t[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
