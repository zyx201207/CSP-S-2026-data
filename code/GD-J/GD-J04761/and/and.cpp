#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2*1e5+10;
int a[N];
int ans=0;
int n,m;
int vis[N];
void dfs(int m,int cnt){
	if(m==0){
		ans=max(ans,cnt);
	}
	for(int i=2;i=n;i++){
		if(vis[i]!=0){
			continue;
		}
		else{
			vis[i]=1;
			int ans=0;
			for(int i=1;i<=min(cnt,a[i]);i++){
				ans=(cnt%10&&a[i]%10);
			} 
			dfs(m--,cnt);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		int l=0;
		while(a[i]){
			l=l*10+a[i]%2;
			a[i]/=2;
		} 
		a[i]=l;
	} 
	dfs(m,a[1]);
	
	cout << ans;
	return 0;
} 
