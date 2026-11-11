#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,s[200010],ans1,f[200010];
struct str{
	int sz,bh;
};
str a[200010];
void dfs(int p){
	if(p>m){
		ans1=s[1];
		for(int i=1;i<=m;i++){
			ans1&=s[i];
		}
		ans=max(ans,ans1);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			s[p]=a[i].sz;
			dfs(p+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i].sz;
		a[i].bh=i;
	}
	dfs(1);
	cout << ans;
	return 0;
}
