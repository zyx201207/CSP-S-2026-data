#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2800005;
int T,dbw,n,d,x[N],dis[N],pre[N],suf[N],pr[N],su[N],sum[N],ans;
pair<int,int> dp[2800005];
bool check(int x,int y){
	for(int i=x;i<=y;i++) dp[i]={1e9,0};
	dp[x]={0,1};
	for(int i=x;i<y;i++){
		int dx=0;
		for(int j=i+1;j<=y;j++){
			dx+=dis[j-1];
			if(dx>d) break;
			if(dp[j].first<dp[i].first+1) continue;
			else if(dp[j].first=dp[i].first+1) dp[j].second+=dp[i].second;
			else dp[j]={dp[i].first+1,dp[i].second};
//			cout<<j<<"\n";
		}
//		cout<<x<<" "<<y<<"  "<<i<<" "<<dp[i].first<<" "<<dp[i].second<<"\n";
	}
//	cout<<dp[y].first<<" "<<dp[y].second<<"\n";
	if(dp[y].second==2) return 1;
	return 0;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i>1) {
			dis[i-1]=x[i]-x[i-1];
			sum[i-1]=sum[i-2]+dis[i-1];
//			cout<<sum[i-1]<<" ";
		}
	}
//	cout<<"\n";
	if(n<4) {
		cout<<"0\n";
		return ; 
	}
	if(n>300){
		for(int i=1;i<=n;i++){
			pre[i]=suf[i]=0;
			if(i>1&&dis[i-1]+dis[i]>d&&dis[i-1]<=d) pre[i]=pre[i-1]+1;
		}
		for(int i=n;i>=1;i--){
			if(i<=n&&dis[i-1]+dis[i]>d&&dis[i]<=d) suf[i]=suf[i+1]+1;
		}
//	for(int i=1;i<=n;i++) cout<<i<<" "<<pre[i]<<" "<<suf[i]<<"\n";
//	pr[1]=1,su[n]=n;
//	for(int r=2,l=1,now=0;r<=n;r++){
//		now+=dis[r-1];
//		while(now>d) now-=dis[l],l++;
//		pr[r]=l;
//	}
//	for(int l=n-1,r=n,now=0;l>=1;l--){
//		now+=dis[l];
//		while(now>d) now-=dis[r-1],r--;
//		su[l]=r;
//	}
		for(int i=2,lk=1,rk=3,lt=1,rt=3;i<=n-2;i++){
			while(sum[i+1]-sum[lk]>d&&lk<i-1) lk++;
			while(sum[rk]-sum[i-2]<=d&&rk<n-1) rk++;
			while(sum[rk-1]-sum[i-2]>d) rk--;
			if(sum[i]-sum[lk-1]>d||sum[rk]-sum[i-1]>d||sum[i+1]-sum[lk-1]<=d||sum[rk]-sum[i-2]<=d) continue;
			while(sum[i]-sum[lt-1]>d&&lt<i-1) lt++;
			while(lt>1&&sum[i]-sum[lt-2]<=d) lt--;
			while(sum[rt+1]-sum[i-1]<=d&&rt<n-1) rt++; 
			int lp=lk,rp=rk+1,l=lt,r=rt+1;
//		cout<<i<<" "<<i+3<<"  "<<lp<<" "<<rp<<"  "<<l<<" "<<r<<"  ";
			l-=pre[l],r+=suf[r];
//		cout<<l<<" "<<r<<"\n";
			ans+=(lp-l+1)*(r-rp+1);
			
			rp++;
		}
		cout<<ans<<"\n";
		ans=0;
		for(int i=1;i<=n;i++) pre[i]=suf[i]=x[i]=dis[i]=pr[i]=su[i]=sum[i]=0;
	}else{
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)){
//				cout<<i<<" "<<j<<"\n";
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	ans=0;
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>dbw>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

0 1
10 3
0 3 6 7 8 9 10 11 14 17


10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
