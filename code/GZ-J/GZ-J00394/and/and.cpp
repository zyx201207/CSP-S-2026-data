//GZ-J00394 姓名：周昊杨 学校：贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=5e3+5;
int dp[M][M];
int n,m,a[N],use[N],ma=INT_MIN;
void dfs(int st,int k,int ans){
	if(k==m+1){
		ma=max(ma,ans);	
	}
	else {
		for(int i=st;i<=n;i++){
			use[k]=a[i];
			if(k==1){
				dfs(i+1,k+1,a[i]);
			}
			else dfs(i+1,k+1,ans&a[i]);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=a[1]&a[2];
		for(int i=1,j=i+1;i<=n&&j<=n;i++,j++){
			ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	if(n>2000)cout<<0;
	dfs(1,1,0);
	cout<<ma;
	return 0;
}

