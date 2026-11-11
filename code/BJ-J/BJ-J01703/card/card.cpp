#include<bits/stdc++.h>
using namespace std;
int p[500005],n,m,a[500005];
int ans[500005],tail;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n<=500){
        for(int i=1;i<=n;i++){
            tail=0;
            for(int j=i;j<=n;j++){
                for(int k=1;k<=tail;k++){
                    if(p[k]==a[j]){
                        tail=k-1;
                        break;
                    }
                }
                p[++tail]=a[j];
            }
            for(int j=1;j<=tail;j++){
                ans[p[j]]++;
            }
        }
        for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
        return 0;
    }
    if(m<=2){
        int cnt=0;
        if(m==1){
            cout<<n;
            return 0;
        }
        int pos1=0,pos2=0;
        for(int i=n-1;i>=1;i--){
            if(a[i]!=a[n]){
                pos1=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=a[n])cnt++;
        }
        if(a[n]==1){
            cout<<n<<' '<<cnt;
        }else {
            cout<<cnt<<' '<<n;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            ans[a[i-1]]=i-1;
        }
    }
    for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
    return 0;
}
