#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5000+5;
ll n,d,x[N],dis[N],f[N],ans,sum[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c,T; cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];

        ans=0;
        for(int i=1;i<=n;i++){ //从i开始
            memset(dis,0x3f,sizeof(dis));
            memset(f,0,sizeof(f));
            memset(sum,0,sizeof(sum));
            int l=i+1,r=n;
            f[i]=0;
            sum[i]=0;
            for(int j=i+1;j<=n;j++){
                if(x[i]+d<x[j]){
                    r=j-1;
                    break;
                }
                dis[j]=1;
                f[j]=1;
                sum[j]=sum[j-1]+f[j];
            }
            //cerr<<l<<' '<<r<<'\n';
            for(int j=r+1;(x[j]-x[j-1]<=d) && j<=n;j++){
                while(x[l]+d<x[j]) l++;
                if(l>r) r=j-1;
                f[j]=sum[r]-sum[l-1];
                if(f[j]==2) ans++;
                sum[j]=sum[j-1]+f[j];
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
