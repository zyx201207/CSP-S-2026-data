#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int wz[300005];
bool f[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int cnt=0;
        memset(f,0,sizeof(f));
        memset(wz,0,sizeof(wz));
        for(int j=i;j<=n;j++){
            cnt++;
            if(!f[a[j]]){
                f[a[j]]=1;
                wz[a[j]]=cnt;
            }else{
                for(int k=1;k<=m;k++){
                    if(wz[k]>wz[a[j]]){
                        f[k]=0;
                        wz[k]=0;
                    }
                }
                f[a[j]]=1;
                wz[a[j]]=cnt;
            }
        }
        for(int j=1;j<=m;j++){
            //cout<<i<<" "<<j<<" "<<t[j]<<"\n";
            if(f[j]){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/
