#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e6+10;
int x[maxn],dp[maxn];
bool ed[maxn],fg[maxn];
signed main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		memset(ed,0,sizeof(ed));
		memset(dp,0,sizeof(dp));
		dp[1]=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d)ed[i]=1;
		}
		int lstd=0,nd=0;
		for(int i=1;i<=n;i++){
			if(ed[i]==1){
				lstd=nd=0;
			}
			nd+=1;
			if(i>2&&x[i-2]+d>=x[i]){
				lstd=nd;
				nd=0;
			}
			if(ed[i]!=1){
				dp[i]=dp[i-1]+lstd;
			}else{
				dp[i]=dp[i-1];
			}
		}
		cout<<dp[n]<<endl;
	}
}
