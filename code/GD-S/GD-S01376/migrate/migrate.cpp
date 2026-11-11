#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
struct node{
	int dis,s;
}dp[N];
int a[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
	if(c==9||c==10){
		while(t--){
			int n,d,cnt=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int sta=a[1],end=a[n],cha=a[2]-a[1];
			int num=d/cha;
//			if(t==3){
//				cerr<<n<<" "<<d<<"\n";
//				for(int i=1;i<=n;i++) cerr<<a[i]<<" ";
//				cerr<<num;
//			}
			if(num==0) cout<<"0\n";
			else cout<<max(0ll,n-2*num+1)<<"\n";
		}
		return 0;
	}
//if(1<=c&&c<=10){
	
	while(t--){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
//			if(i!=1&&a[i]-a[i-1]>)
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) dp[j].dis=1e18,dp[j].s=0;
			dp[i]={0,1};
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					if(a[k]-a[j]>d) break;
					if(dp[j].dis==dp[k].dis-1) dp[k].s+=dp[j].s;
					else if(dp[j].dis+1<dp[k].dis) dp[k].dis=dp[j].dis+1,dp[k].s=dp[j].s;
				}
				if(dp[j].s==2) cnt++;
//				cout<<dp[j].s<<" ";
			}
		}
		cout<<cnt<<"\n";
	}
//}
	return 0;
}

