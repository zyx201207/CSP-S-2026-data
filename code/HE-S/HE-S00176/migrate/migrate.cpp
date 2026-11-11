#include   <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
int g[N][N];
void solve(){
    int n,d,ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
    }
    for(int i=n-1;i>=1;i-=1){
        for(int j=n+i;j<=min(n,i+d);j+=1){
            if(a[i]+d<a[j]){
                int cnt=0,len=INT_MAX,k=i;
                while(k<=j&&a[i]+d>=a[k]){
                    len=min(len,g[k][j]+1);
                    k+=1;
                }
                k=i;
                while(k<=j&&a[i]+d>=a[k]){
                    if(g[k][j]+1==len)cnt+=1;
                    k+=1;
                }
                if(cnt==2)ans+=1;
                g[i][j]=len;
            }
            else{
                g[i][j]=1;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    solve();
    return 0 ;
}
