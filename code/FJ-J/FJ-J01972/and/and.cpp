#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000005];
int ans;
int b[1000005];
bool book[1000005];
void dfs(int step,int x){
	b[step]=x;
	if(step==m){
		int sum=b[1];
		for(int i=2;i<=m;i++) sum=sum&b[i];
		ans=max(sum,ans);
	}
	for(int i=1;i<=n;i++){
		if(book[i]||a[i]>x||a[i]==0) continue;
		book[i]=true;
		dfs(step+1,a[i]);
		book[i]=false;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		book[i]=true;
		dfs(1,a[i]);
		book[i]=false;
	}
	cout<<ans;
	return 0;
}
