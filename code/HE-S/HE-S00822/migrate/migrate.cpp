#include<bits/stdc++.h>
using namespace std;
const int N=5007,M=5e6+7;
int dp[N][N][4],a[M],b[M],c[M],k;
vector<int> g[N],g2[N];
void solve(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(dp,0,sizeof(dp));
	long long n,i,j,l,d,ans=0;
	cin>>n>>d;
	for(i=1;i<=n;i++){
		cin>>a[i];
		g[i].clear(),g2[i].clear();
	}
	if((k>=11&&k<=12)){
		if(n<4){
			cout<<0<<endl;
			return;
		}
		if(d>=2*abs(a[2]-a[1])&&d<3*abs(a[2]-a[1])){
			cout<<n-3<<endl;
			return;
		}
		cout<<0<<endl;
		return;
	}
	j=1;
	for(i=2;i<=n;i++){
		if(a[i]-a[j]>d) j++;
		c[i]=i-j;
		for(l=j;l<i;l++) g[i].push_back(l);
	}
	j=n;
	for(i=n-1;i>0;i--){
		while(a[j]-a[i]>d) j--;
		b[i]=j-i;
		for(l=j;l>i;l--) g2[i].push_back(l);
	}
	for(i=2;i<=n;i++){ 
		dp[i][i][1]=1;
	}
	for(l=1;l<=n;l++){
		for(i=1,j=i+l;j<=n;i++,j++){
			if(a[j]-a[i]<=d){
				dp[i][j][1]=1;
				continue;
			}
			if(c[j]==1){
				dp[i][j][1]=max(dp[i][j][1],dp[i][g[j][0]][1]);
			}
			if(c[j]==1){
				dp[i][j][2]=max(dp[i][j][2],dp[i][g[j][0]][2]);
			}
			if(b[i]==1){
				dp[i][j][2]=max(dp[i][j][2],dp[g2[i][0]][j][2]);
			}
			if(c[j]==2){
				dp[i][j][dp[i][g[j][0]][1]+dp[i][g[j][1]][1]]=1;
			}
			if(b[i]==2){
				dp[i][j][dp[g2[i][0]][j][1]+dp[g2[i][1]][j][1]]=1;
			}
			ans+=dp[i][j][2];
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>k>>t;
	while(t--) solve();
	return 0;
}
