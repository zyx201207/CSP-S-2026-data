//GZ-J00507 陈俊瑞 兴义市弘毅中学
#include<iostream>
using namespace std;
typedef long long ll;
#define maxn 200005
int n,m;
ll a[maxn],ans=0;
ll dp[2005][2005];
void dfs(int len,int lst,ll val){
	if(len==m){
		ans=max(val,ans);
		dp[len][lst]=ans;
	}
	for(int i=lst+1;i<=n;i++){
		if(dp[len-1][lst])dp[len][lst]=dp[len-1][lst]&a[i];
		else dfs(len+1,i,val&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20)
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(a[i]^a[j],ans);
		}
	}
	else
	for(int i=1;i<=n;i++){
		dfs(1,i,a[i]);
	}
	
	cout<<ans<<'\n';
	return 0;
}
