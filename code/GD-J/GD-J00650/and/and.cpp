#include <bits/stdc++.h>
using namespace std;
int a[200005];
//void dfs(int sum,int idx,int cnt){
//	if(cnt==m||idx==n+1){
//		ans=max(ans,sum);
//		cout<<sum<<endl;
//		return ;
//	}
//	dfs(sum,idx+1,cnt);
//	dfs(sum&a[idx],idx+1,cnt+1);
//	
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) f=0;
	}
	if(f){
		int ans=a[n];
		for(int i=n-1;i>=n-m;i--) ans&=a[i];
		cout<<ans; 
		return 0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
}
