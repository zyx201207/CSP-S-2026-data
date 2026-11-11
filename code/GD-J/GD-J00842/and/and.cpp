#include<bits/stdc++.h> 
using namespace std;
int a[200001],ans=(1<<31)-1,dfs_ans=0;
vector<int>_ans;
bool vis[200001];
int n,m;
void dfs(int t){
	if(t>=n){
		int sum=(1<<31)-1;
		for(int i:_ans){
			sum&=i; 
		}
		dfs_ans=max(dfs_ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		_ans[t]=a[i];
		dfs(t+1);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin >> n >> m;
	bool A=true;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if((1<<int(log2(a[i]+1)))-1!=a[i]) A=false;
	}
	if(n<=20){
		for(int i=1;i<=m;i++) _ans.push_back(114514);
		dfs(0);
		cout << dfs_ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout << ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	if(A){
		sort(a+1,a+n+1);
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i];
		}
		return 0;
	}
	cout << 0;
	return 0;
}
// 13/20 65·Ö 
