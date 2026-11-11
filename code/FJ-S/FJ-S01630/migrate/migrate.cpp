#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=2e18;
int n,d,x[N],dp1[305][305][2],ans;
void test1(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp1[i][j][0]=INF;
			dp1[i][j][1]=0;
			if(i==j) dp1[i][j][0]=0,dp1[i][j][1]=1;
			else if(x[j]-x[i]<=d) dp1[i][j][0]=1,dp1[i][j][1]=1;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++){
			int j=i+len-1;
			if(j>n) break;
			for(int k=i+1;k<=j-1;k++){
				if(x[k]-x[i]>d) continue;
				if(x[j]-x[k]>d) continue;
				if(dp1[i][j][0]>dp1[i][k][0]+dp1[k][j][0]){
					dp1[i][j][0]=dp1[i][k][0]+dp1[k][j][0];
					dp1[i][j][1]=dp1[i][k][1]*dp1[k][j][1];
				}else if(dp1[i][j][0]==dp1[i][k][0]+dp1[k][j][0])
					dp1[i][j][1]+=dp1[i][k][1]*dp1[k][j][1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp1[i][j][1]==2){
//				cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
bool dc(){
	for(int i=1;i<=n-1;i++) if(x[i+1]-x[i]!=x[2]-x[1]) return false;
	return true;
}
void test2(){
	for(int i=2;i<=n;i++) x[i]-=x[1];
	x[1]=0;
	int dd=x[2]-x[1],lng=d/dd;
	if(lng==1) cout<<0<<endl;
	else cout<<max(0ll,n-2*lng+1)<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin>>T;cin>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(dc()){
			test2();
			continue;
		}
		if(n<=300){
			test1();
			continue;
		}
		test1();
	}
	return 0;
}
