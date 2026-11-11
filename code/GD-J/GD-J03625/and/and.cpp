#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[214514];
bool v[214514];
long long ans,ans1;
void dfs(int c,long long k){
	if(c>=m){
		ans=max(ans,k);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			long long t=k&a[i];
			dfs(c+1,t);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		v[i]=1;
		ans=0;
		dfs(1,a[i]);
		v[i]=0;
		ans1=max(ans,ans1);
	}
	cout << ans1;
	return 0;
}
