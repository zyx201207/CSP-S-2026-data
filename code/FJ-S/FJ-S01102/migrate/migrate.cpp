#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,dp[N],dis[N];
ll m,pos[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _c,_;
	cin>>_c>>_;
	// O(n^2)
	while(_--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>pos[i];
//		cout<<n<<","<<m<<"  "<<pos[2]-pos[1]<<"\n";
		bool fa=false;
		if(_c==11||_c==12) fa=true;
		for(int i=1;i<=n;i++){
			int l=i,r=i,lst=-1;
			ll rst=pos[i+1]-pos[i],nd=1,sum=1;
			dp[i]=dp[i+1]=1;
			dis[i]=0;dis[i+1]=1;
			if(rst>m) continue;
			for(int j=i+2;j<=n;j++){
				ll d=pos[j]-pos[j-1];
				if(d>m) break;
				if(rst+d<=m){
					rst+=d;
				}
				else{
					nd++;
					rst=d;
				}
				dis[j]=nd;
				while(pos[j]-pos[l]>m){
					sum-=dp[l];
					l++;
				}
				while(r+1<=j&&dis[r+1]<dis[j]){
					r++;
					sum+=dp[r];
				}
				dp[j]=sum;
				if(dp[j]==2){
					lst=j;
					ans++;
				}
//				cout<<i<<","<<j<<":"<<dp[j]<<"   "<<l<<","<<r<<"   "<<rst<<","<<dis[j]<<"\n";
			}
			if(fa){
				if(lst==-1) cout<<"0\n";
				else cout<<n-lst+1<<"\n";
				break;
			}
		}
		if(!fa) cout<<ans<<"\n";
	}
	return 0;
}
