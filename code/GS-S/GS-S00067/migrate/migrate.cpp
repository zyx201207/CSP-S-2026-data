#include<bits/stdc++.h>
#define int long long
#define inf (int)2e18
using namespace std;
const int maxn=2e6+5;
int c,t,n,d,arr[maxn],dp[maxn],cnt;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>arr[i];
		if(c==11||c==12){
			int diff=arr[2]-arr[1];
			for(int i=d+1;i<=2*d;i+=diff)cnt+=(arr[n]-arr[1]+i-1)/i;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++)if(arr[j]+d>=arr[i])dp[i]+=dp[j];
				if(dp[i]==2)cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
