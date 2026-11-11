#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[int(2e5+5)],ax[int(2e5+5)][32],ji[33],jg[33],ans=0;
bool vis[int(2e5+5)];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            ax[i][j]=(a[i]>>j)%2;
            ji[j]+=ax[i][j];
        }

    }
    for(int i=30;i>=0;i--){
        if(ji[i]>=m){
            ll pd=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    pd+=ax[j][i];
                }
            }
            if(pd>=m){
                for(int j=1;j<=n;j++){
                    if(!vis[j]){
                        if(ax[j][i]==0){
                            vis[j]=true;
                        }
                    }
                }
                jg[i]=1;
            }
        }
    }
    for(int i=30;i>=0;i--){
        ans=ans*2+jg[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
