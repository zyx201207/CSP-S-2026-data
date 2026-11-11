#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,vis[1000005];
deque <int> q;
void dfs (int cnt){
	if (cnt==m&&q.size()==m){
		long long c=q.front();
		for (int i=0;i<q.size();i++){
			c=c&q[i];
		}
		ans=max(ans,c);
		return ;
		
	}
	else {
		for (int i=1;i<=n;i++){
			if (vis[i]==0){
				vis[i]=1;
				q.push_back(a[i]);
				dfs(cnt+1);
				q.pop_back();
				vis[i]=0;
			}
		}
	}
}
int main (){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
