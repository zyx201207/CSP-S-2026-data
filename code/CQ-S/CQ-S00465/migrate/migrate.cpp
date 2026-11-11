#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
bool bbb;
const int N=2e6+5;
ll c,t,n,d,x[N],s[N][4],to[N],ans;
PII dp[N][4];
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return;
}
ll getid(ll b0,ll b1){
	if(b0==0&&b1==0) return 3;
	if(b1==2) return 2;
	if(b0==1&&b1==1) return 1;
	return 0; 
}
bool eee;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cerr<<abs(&bbb-&eee)/1024.0/1024.0;
	fast();
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			ll l=i+1,r=n;
			to[i]=i;
			while(l<=r){
				ll mid=(l+r)>>1;
				if(x[mid]-x[i]<=d) to[i]=mid,l=mid+1;
				else r=mid-1;
			}
		}
		for(int i=1;i<=n;i++){
			ll b0=0,b1=0,res=0;
			if(to[i]>i&&to[i-1]<to[i]) b1=1;
			if(to[i]-1>i&&to[i-1]<to[i]-1) b0=1;
			dp[i][0]={res,getid(b0,b1)};
			b0=0,b1=0;
			res=to[i-1]-to[i-2];
			if(to[i-1]>=i&&to[i-2]<i) res--;
			if(to[i]>i&&to[i-1]>=to[i]&&to[i-2]<to[i]) b1=2;
			else if(to[i]>i&&to[i-1]<to[i]) b1=1;
			if(to[i]-1>i&&to[i-1]>=to[i]-1&&to[i-2]<to[i]-1) b0=2;
			else if(to[i]-1>i&&to[i-1]<to[i]-1) b0=1;			 
			dp[i][1]={res,getid(b0,b1)}; 
			b0=0,b1=0;
			res=to[i]-to[i-1];
			if(to[i]>=i&&to[i-1]<i) res--;
			if(to[i]>i&&to[i-1]<to[i]) b1=2;
			if(to[i]-1>i&&to[i-1]<to[i]-1) b0=2;
			dp[i][2]={res,getid(b0,b1)};
			dp[i][3]={0,3};			
		}
		for(int i=n;i>=1;i--){
			if(to[i]==i) s[i][0]=s[i][1]=s[i][2]=s[i][3]=0;
			else{
				s[i][0]=dp[i][0].first+s[to[i]][dp[i][0].second];
				s[i][1]=dp[i][1].first+s[to[i]][dp[i][1].second];
				s[i][2]=dp[i][2].first+s[to[i]][dp[i][2].second];
				s[i][3]=dp[i][3].first+s[to[i]][dp[i][3].second];
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(to[i]==i) continue;
			if(to[i]==i+1) ans+=s[to[i]][0];
			else ans+=s[to[i]][1];
		}
		cout<<ans<<endl;
	} 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
