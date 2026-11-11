#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long ans;
//void dfs(int idx,int cnt,long long sum){
//	cout<<cnt<<' '<<a[idx]<<' '<<sum<<endl;
//	if(cnt==m){
//		ans=max(ans,sum);
//		return;
//	}
//	if(sum==0)return;
//	if(idx==n)return;
//	dfs(idx+1,cnt+1,sum&a[idx]);
//	dfs(idx+1,cnt,sum);
//	
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n;i>=(n-m+1);i--){
		ans&=a[i];
	}
//	dfs(1,1,a[1]);
//	dfs(1,0,1073741823);
	cout<<ans;
	return 0;
}
//2 ^ 30 = 1073741824
//111111111111111111111111111111 = 1073741823
