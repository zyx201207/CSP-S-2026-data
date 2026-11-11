#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int f[200005],a[200005],k[200005],n,i,m,maxn=INT_MIN;
void bfs(int step){
	if(step==m+1){
		int u=f[1];
		for(i=2;i<=m;i++){
			u=u&f[i];
		}
		maxn=max(maxn,u);
		return ;
	}
	for(k[step]=1;k[step]<=n;k[step]++){
		if(mp[k[step]]==0&&f[step-1]<=a[k[step]]){
			f[step]=a[k[step]];
			mp[k[step]]=1;
			bfs(step+1);
			f[step]=0;
			mp[k[step]]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bfs(1);
	cout<<maxn;
	return 0;
}
