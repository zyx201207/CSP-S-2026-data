#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N],mark[N],ls[N];
int ans;
void dfs(int step,int cnt){//
	if(cnt == m+1){
		int cnt = ls[1];
		
		for(int i = 1;i <= m;i++){
//			printf("ts:ls[%d] = %d",i,ls[i]);
			cnt = cnt&ls[i];
		}
		ans = max(ans,cnt);
//		puts("");
		return ;
	}
//	dfs(step+1,cnt);
	for(int i = step;i <= n;i++){
		dfs(step+1,cnt);
		if(mark[i] == 0){
			ls[cnt] = a[i];
			mark[i] = 1;
			dfs(step+1,cnt+1);
			mark[i] = 0;			
		}

	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 20){
		dfs(1,1);
		cout << ans;
		return 0;
	}
	ans = 0;
	if(m == 1){
		sort(a+1,a+1+n);
		cout << a[n];
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 1;i <= n;i++){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				ans = max(ans,(a[i]&a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	
	sort(a+1,a+1+n);
	for(int i = n;i >= n-m+1;i--){
		if(i == n){
			ans = a[i];
		}else{
			ans = ans & a[i];
		}
	}
	cout << ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
