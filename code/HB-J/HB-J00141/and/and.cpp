#include <bits/stdc++.h>
using namespace std;
int m,n,a[200009],book[200009],ans=-1;
void dfs(int p,int sum){
	if(p>=m){
		//for(int i=1;i<=n;i++){
		//	cout << book[i];
		//}
		//cout <<'|'<<sum<< '\n';
		ans=max(sum,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==1) continue;
		book[i]=1;
		dfs(p+1,sum&a[i]);
		book[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		book[i]=1;
		dfs(1,a[i]);
		book[i]=0;
	}
	cout << ans;
	return 0;
}
