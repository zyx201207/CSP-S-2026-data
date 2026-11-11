#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+10;
int c,T,n,ans;
ll a[N],d[N][2],m;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            d[i][0]=0;
            d[i][1]=1;
            for(int j=i+1;j<=n;j++){
                d[j][0]=9e18;
                d[j][1]=0;
                for(int k=i;k<j;k++){
                    if(a[j]-a[k]<=m){
                        if(d[j][0]>d[k][0]+1){
                            d[j][0]=d[k][0]+1;
                            d[j][1]=d[k][1];
                        }else if(d[j][0]==d[k][0]+1){
                            d[j][1]+=d[k][1];
                        }
                    }
                }
                if(d[j][1]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
