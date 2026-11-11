#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[200005];
bool vis[200005];
int ans;
int  sum=-1e9;
bool cmp(string x,string y){
	if(x.size()!=y.size()){
		return x.size()<y.size();
	}
	return x<y;
}
void dfs(int c){
	if(c==m){
		sum = max(sum,ans);
		//cout << sum<<" ";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i] = true;
			int last = ans;
			if(c==0){
				ans = s[i];
			}else{
				ans = ans&s[i];;
			}
			dfs(c+1);
			ans = last;
			vis[i] = false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		s[i] = x;
	}
	dfs(0);
	cout << sum << endl;
	return 0;
}
