#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],k[300010],l[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans[a[n]]=n;
    int e=0;
    for(int i=1;i<=n;i++){
        for(int j=i,u=i;j<=n,u<=n;j++,u++){
            if(l[k[j]]>1){
                for(int r=1;r<=i;r++){
                    if(k[r]==k[j]){
                        e=r;
                        break;
                    }
                }
                for(int r=e;r<=n;r++){
                    l[k[r]]--;
                    k[r]=0;
                }
                j=e;
            }else{
                k[j]=a[u];
                l[k[j]]++;
            }
        }
        for(int i=1;i<=m;i++){
            if(l[i]>0) ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
