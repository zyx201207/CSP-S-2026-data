#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000010;
int c,t,n,d,x[N],dp[N],s[N],pre[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    if(c<=10){
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=0,s[i]=1,pre[i]=1,pre[i-1]=0;
            for(int j=i+1,k=i,r=i;j<=n;j++){
                s[j]=0;
                while(x[j]-x[k]>d){k++;}
                if(j==k) break;
                dp[j]=dp[k]+1;
                for(int w=k;w<=j;w++){
                    if(dp[w]==dp[k]) s[j]+=s[w];
                    else break;
                }
                if(s[j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    else{cout<<0<<'\n';}
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){solve();}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
