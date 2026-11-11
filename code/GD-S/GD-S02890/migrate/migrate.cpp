#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long n,d,c,t,dp[maxn],st[maxn],a[maxn],mi[maxn],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(mi,0x3f3f3f3f,sizeof(mi));
		mi[1]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				if(mi[i]+1<mi[j]){
					mi[j]=mi[i]+1;
					dp[j]=1;
				}else if(mi[i]+1==mi[j])dp[j]++;
			}
		}
		for(int i=1;i<=n;i++)if(dp[i]==2)ans++;
		cout<<ans<<'\n';
	}
	return 0;
} 
