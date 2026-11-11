#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],l[500005],n,m;
int mark[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int tot=0;
        memset(mark,0,sizeof(mark));
        for(int j=i;j<=n;j++){
            //if(i==32) cout<<j<<' '<<a[j]<<' '<<mark[a[j]]<<' '<<tot<<'\n';
            if(!mark[a[j]]||mark[a[j]]>tot){
                mark[a[j]]=++tot;
                l[tot]=a[j];
            }
            else if(l[mark[a[j]]]!=a[j]){
                mark[a[j]]=++tot;
                l[tot]=a[j];
            }
            else{
                tot=mark[a[j]];
            }
            //if(a[j]==47) cout<<'\n';
        }
        //cout<<'\n';
        for(int j=1;j<=tot;j++){
            ans[l[j]]++;
            //if(i==32) cout<<l[j]<<' ';
        }
        //cout<<i<<' '<<ans[47]<<'\n';
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
