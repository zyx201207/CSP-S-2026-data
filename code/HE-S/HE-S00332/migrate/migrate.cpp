#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+100;
int n,d;
int a[N];
int dp[N];
int fl[N];
bool check1(int x,int y){
	if(a[y]>=x) return 1;
	return 0;
}
int b_s1(int s,int e,int x){
	int head=s,tail=e,mid,ans=-1;
	while(head<=tail){
		mid=(head+tail)/2;
		if(check1(x,mid)) ans=mid,tail=mid-1;
		else head=mid+1;
	}
	return ans;
}
int b_s2(int s,int e,int x){
	int head=s,tail=e,mid,ans=-1;
	while(head<=tail){
		mid=(head+tail)/2;
		if(dp[mid]!=0 && dp[mid]<=x) ans=mid,head=mid+1;
		else tail=mid-1;
	}
	return ans;
}
void solve(){
	memset(a,0,sizeof a);
	memset(dp,0,sizeof dp);
	memset(fl,0,sizeof fl);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(int k=1;k<=n;k++){
		memset(fl,0,sizeof fl);
		memset(dp,0,sizeof dp);
		dp[k]=1;
		fl[k]=1;	
		for(int i=k+1;i<=n;i++){
			int mini=b_s1(k,i-1,a[i]-d);
			int mind=dp[mini];
			int maxi=b_s2(mini,i-1,mind);
			int maxd=dp[maxi];
			dp[i]=mind+1;
			if(maxi-mini==1 && fl[maxi]==fl[mini] && fl[mini]==1) cnt++,fl[i]=2;
			else if(maxi==mini && fl[maxi]==2) cnt++,fl[i]=2;
			else if(maxi==mini && fl[maxi]==1) fl[i]=1;
			else fl[i]=3;
		}
	}
	cout<<cnt<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

