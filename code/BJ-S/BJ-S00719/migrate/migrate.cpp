#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int abc;
int q;
int n,m;
int a[N],f[N],d[N];
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>abc>>q;
    while(q--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        f[1]=1;d[1]=0;
        for(int k=1;k<n;k++){
            f[k]=1;
            for(int i=k+1;i<=n;i++){
                int j=lower_bound(a+1,a+1+n,a[i]-m)-a;
                if(j==i){
                    f[i]=0;
                    d[i]=0;
                    continue;
                }
                d[i]=d[j]+1;
                while(d[j]==d[i]-1){
                    f[i]+=f[j];
                    j++;
                }
            }
            for(int i=1;i<=n;i++){
                //cout<<f[i]<<" ";
                if(f[i]==2) ans++;
            }
            for(int i=1;i<=n;i++){
                f[i]=0;d[i]=0;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
