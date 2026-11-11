#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[300010],op[500010],id,l;
bool f[300010],del[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(del,0,sizeof(del));
        memset(f,0,sizeof(f));
        memset(op,0,sizeof(op));
        id=0;
        for(int j=i;j<=n;j++){
            bool ok=0;
            for(int k=1;k<=id;k++) if(a[j]==op[k]&&del[k]==0) ok=1;
            if(ok==1){
                for(int k=1;k<=id;k++){
                    if(op[k]==a[j]&&del[k]==0){
                        l=k;
                        break;
                    }
                }
                for(int k=l;k<=id;k++) del[k]=1;
            }
            id++;
            op[id]=a[j];
            f[a[j]]=1;
        }
        for(int j=1;j<=id;j++){
            if(del[j]==0){
                sum[op[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
    return 0;
}
