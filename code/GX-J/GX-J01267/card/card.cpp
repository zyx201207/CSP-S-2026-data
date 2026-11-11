#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s,e[300005];
int z[500005],u=0;
bool c[500005][3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(c[s][a[j]]==0){
                u++;
                z[u]=a[j];
                c[s][a[j]]=1;
            }else{
                int flag=0;
                for(int k=u;k>=0;k--){
                    if(flag) break;
                    if(z[k]==a[j])flag=1;
                    c[s][z[k]]=0;
                    z[k]=0;
                    u--;
                }
                u++;
                z[u]=a[j];
                c[s][a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(c[s][j]) e[j]++;
        }
        s++;
    }
    for(int i=1;i<=m;i++){
        cout<<e[i]<<' ';
    }
    return 0;
}
