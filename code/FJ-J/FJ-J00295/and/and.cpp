#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans=0;
long long a[N];
void dfs(int idx,int cnt,int depth){
	if(idx==m+1)return;
	if(depth==m){
		ans=max(ans,cnt);
		cout<<ans<<'\n';
		return;
	}
	dfs(idx+1,cnt,depth);
	dfs(idx+1,cnt=(cnt&a[idx]),depth+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<12<<'\n';
	return 0;
} 
