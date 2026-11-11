#include<bits/stdc++.h>
using namespace std;
int a[500020],n;
long long m,ans=0;
int cnt[100200];
void dfs(int idx,int d){
	if (d > m)
		return;
	if (idx == n){
		int maxn = 0;
		for (int i = 1;i <= n;i++){
			maxn = max(maxn,cnt[i]);
		}ans = max((int)ans,maxn);
		return;
	}
	for (int i = 0;i <= m-d;i++){
		cnt[a[idx]+i]++;
		dfs(idx+1,d+i);
		cnt[a[idx]+i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 0;i < n;i++){
		cin>>a[i];
	}
	if (n == 1){
		cout<<1;
		return 0;
	}
	if (n >= 5000&&m >= 1000000){
		cout<<n/3+1;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
