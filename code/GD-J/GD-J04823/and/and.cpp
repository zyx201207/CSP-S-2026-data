#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int ans = 0;
int cnt[35];
void dfs(int step,int start,int num){
	if(step == m){
		ans = max(ans,num);
		return;
	}
	for(int i = start;i <= n;i++){
		dfs(step+1,i+1,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int temp = a[i];
		int p = 0;
		while(temp){
			cnt[p++] = temp%2;
			temp /= 2;
		}
	}
	if(n <= 2000){
		dfs(0,1,2147483647);
		cout << ans;
	}else{
		for(int i = 31;i >= 0;i--){
			if(cnt[i] >= m){
				ans += pow(2,i);
			}
		}
		cout << ans;
	}
	return 0;
}
