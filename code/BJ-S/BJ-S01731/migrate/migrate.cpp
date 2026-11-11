#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int c,T;
int n,d,ans;
int a[N];
int p[N][N];
int v[N][N];
int f[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>a[i];
        a[n+1]=3e18+5;
        for(int i=1;i<=n;++i){
            for(int j=i-1;j>=1;--j) p[j][i]=p[i][j]=(a[i]-a[j]-1)/d+1;
            for(int j=i+1;j<=n;++j) p[j][i]=p[i][j]=(a[j]-a[i]-1)/d+1;
        }
        for(int i=1;i<=n;++i) f[i]=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
        int cnt=0,cnt2=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n-i;++j){
                if(j<=f[i]) cnt=1,cnt2=1;
                else cnt=0,cnt2=0;
                for(int k=j+1;k<j+i;++k){
                    if((p[i][k]+p[k][j]==p[i][j])&&v[i][k]&&v[k][j]) ++cnt;
                    if(p[i][k]+p[k][j]==p[i][j]) ++cnt2;
                    if(cnt2>1) break;
                }
                if(cnt==1&&cnt2==1){
                    ++ans;
                    v[i][j]=1;
                }
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}