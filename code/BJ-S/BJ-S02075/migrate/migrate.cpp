#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000000+10,M=5000+10;
int f[M][M],g[M][M],ed[M][M];
int lf[N],a[N],n,d,testcase;

inline int check(int u){
    if(a[u+3]<=(a[u]+d))return 0;
    if(a[u+2]>(a[u]+d))return 0;
    if(a[u+3]>(a[u+1]+d))return 0;
    return 1;
}

inline void test(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lf[i]=i==1?1:lf[i-1];
        while(a[i]-a[lf[i]]>d)lf[i]++;
        //cout<<i<<": "<<lf[i]<<endl;
    }
    if(n<=300&&testcase<=6){
        int ans=0;
        for(int i=1;i<=n;i++){
            g[i][i]=1;
            for(int j=i+1;j<=n;j++){
                f[i][j]=n,g[i][j]=0;
                for(int k=max(i,lf[j]);k<j;k++){
                    f[i][j]=min(f[i][j],f[i][k]+1);
                }
                for(int k=j-1;k>=i&&k>=lf[j]&&f[i][k]>=f[i][j]-1;k--){
                    if(f[i][k]==f[i][j]-1)g[i][j]+=g[i][k];
                }
                if(g[i][j]==2)ans++;
                if(g[i][j]>2)g[i][j]=3;
            }
        }
        /**for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<f[i][j]<<","<<g[i][j]<<";   ";
            }cout<<"\n";
        }**/
        cout<<ans<<'\n';return;
    }
    if(testcase<=10){
        int ans=0;
        for(int i=1;i<=n;i++){
            g[i][i]=1;ed[i][0]=i;
            for(int j=i+1,lst=i;j<=n;j++){
                f[i][j]=n,g[i][j]=0;lst=max(lst,lf[j]);
                if(lst==j)break;
                ed[i][f[i][j]=f[i][lst]+1]=j;
                g[i][j]=g[i][ed[i][f[i][lst]]]-g[i][lst-1];
                //cout<<"\t"<<i<<','<<j<<": "<<f[i][j]<<','<<g[i][j]<<endl;
                if(g[i][j]==2)ans++;
                if(g[i][j]>2)g[i][j]=3;
                g[i][j]+=g[i][j-1];
            }
        }
        cout<<ans<<'\n';return;
    }
    int ans=0;for(int i=1;i+3<=n;i++)if(check(i))ans++;
    cout<<ans<<'\n';return;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;cin>>testcase>>t;while(t--)test();
    return 0;
}
