#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,m;
long long ans[500010];
long long mx=-1e9;
void dfs(int pos,int cnt){
	if(cnt==m){
		for(int i=1;i<cnt;i++){
			ans[i]=(ans[i]&ans[i-1]);
		}
		mx=max(mx,ans[m-1]);
		return;
	}
	if(pos==n+1) return;
	dfs(pos+1,cnt);
	ans[cnt]=a[pos];
	dfs(pos+1,cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<mx;
	return 0;
}
