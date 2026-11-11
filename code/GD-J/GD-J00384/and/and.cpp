#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,ans,minn = 999999999;
long long a[200005];
void dfs(int x,int id,long long sum){
	if(id >= m){
		ans = max(sum,ans);
		return;
	}
	if(m - id > n - x){
		return;
	}
	dfs(x + 1,id + 1,sum & a[x]);
	dfs(x + 1,id,sum);
}
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin >> n >> m;
	bool f = 1,f1 = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(a[i],maxn);
		minn = min(minn,a[i]);
		if(a[i] >= 4){
			f = 0;
		}
		if(a[i] == 2){
			f1 = 0;
		}
	}
	
	long long j = 1;
	for(int i = 1; i <= 31; i++){
		j = j * 2;
	}
	j -= 1;
	if(m == 1){
		cout << maxn;
	}else if(m == n){
		for(int i = 1; i <= n; i++){
			j = j & a[i];
		}
		cout << j;
	}else if(f){
		sort(a + 1, a + 1 + n);
		if(a[m] == 1 && !f1){
			cout << 0;
		}else{
			cout << a[m];
		}
	}else
	if(n <= 20 || m == 2 || n - m == 1){
		
		dfs(1,0,j);
		cout << ans;
	}else{
		cout << minn;
	}
	
	return 0;
} 













