#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt;
long long a[N],ans,mx,mn=1;
void dfs(int l,int u,long long s){
	if(cnt>=86351){
		cout<<ans;
		exit(0);
	}
	if(u>m){
		ans=max(ans,s);
		return;
	}
	if(l>n||s<=ans){
		return;
	}
	cnt++;
	dfs(l+1,u+1,s&a[l]);
	cnt++;
	dfs(l+1,u,s);
}
int C(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=31;i++){
		mn*=2;
	}
	mn--;
	long long mm=mn;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mm&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==n){
		cout<<mm;
		return 0;
	}else if(m==2){
		for(int i=1;i<=min((int)9e7/n+1,n);i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,C);
	dfs(1,1,mn);
//	long long s=1;
//	for(int i=1;i<=31;i++){
//		s*=2;
//	}
//	s--;
//	for(int i=0;i<=n;i++){
//		dp[i][0]=s;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
//		}
//	}
//	cout<<dp[n][m];
	cout<<ans;
	return 0;
}

