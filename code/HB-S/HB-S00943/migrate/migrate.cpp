#include <bits/stdc++.h>
using namespace std;
const int mx=2E5;
long long a[mx],dp[mx],dps[mx];
long long n,m,c,t,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        dps[1]=1;
        dp[1]=0;
        ans=0;
        for(int i=2;i<=n;i++) dp[i]=99999,dps[i]=0;
        for(int i=1;i<=n;i++,dp[i]=0,dps[i]=1){
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[k]+m<a[j]) break;
                    int x=dp[k]+1,s=dps[k];
                    if(x==dp[j]) dps[j]+=s;
                    else if(x<dp[j]) dp[j]=x,dps[j]=s;
                }
//                for(int k=1;k<=n;k++) cout<<dps[k]<<' ';
//                cout<<'\n';
                if(dps[j]==2) ans++;
            }
            for(int j=1;j<=n;j++) dp[j]=99999,dps[j]=0;
        }
        cout<<ans<<'\n';
	}
	return 0;
}
