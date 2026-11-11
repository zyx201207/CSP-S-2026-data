#include<bits/stdc++.h>
using namespace std;
int a[200010];
struct used{
	int x;
}b[200010];
long long ans = 0,num = 1;
int cnt,cnd;
void dfs(int k){
	if(k == cnt + 1){
		ans = max(ans,num);
		return;
	}else{
		for(int i = 1;i <= cnd;i++){
			int nun = num;
			if(b[i].x == 0){
				num = a[i] & num;
				b[i].x = 1;
				dfs(k+1);
				num = nun;
				b[i].x = 0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cnt = m;
	cnd = n;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
		b[i].x = 0;
	}
	for(int i = 1;i <= n;i++){
		num = a[i];
		b[i].x = 1;
		dfs(2);
	}
	cout << ans;
	return 0;
}
