#include<bits/stdc++.h>
#define ll long long
//unsigned long long
//priority_queue<int,vector<int>,greater<int>>;
using namespace std;
int n,m,a[200005],ans,ma;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	sort(a+1,a+n+1,cmp);
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	int dp[n+1][m+1]={0};
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=min(m,i);++j){
			dp[i][j]=max(int(dp[i-1][j-1]&a[i]),dp[i-1][j]);
		}
	}
	for(int i=1;i<=n;++i){
		ans=max(dp[i][m],ans);
	}
	cout<<ans;
	return 0;
}
