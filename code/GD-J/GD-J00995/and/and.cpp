#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
const int N = 200010;
int n,m;
ll a[N];
bool vis[N];
ll ans;
void dfs(ll x,ll w){
	if(x==m){
		ans = max(ans,w);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i])continue;
		vis[i] = true;
		dfs(x+1,w&a[i]);
		vis[i] = false;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n<=20){
		for(int i = 1;i <= n;i++){
			vis[i] = true;
			dfs(1,a[i]);
			vis[i] = false;
		}
		cout << ans;
		return 0;
	}
	else if(n<=2000){
		if(m==1){
			for(int i = 1;i <= n;i++)ans = max(ans,a[i]);
		}
		else if(m==n){
			ans = a[1];
			for(int i = 2;i <= n;i++){
				ans&=a[i];
			}
		}
		else{
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					ans = max(ans,a[i]&a[j]);
				}
			}
		}
		cout << ans;
		return 0;
	}
	else{
		cout << a[n];
		return 0;
	}
	return 0;
}
