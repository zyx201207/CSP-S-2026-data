#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];

int n,m;
int ans = -1;


//jz当前基准下标, tmp分配余额 
//相同值个数 
void dfs(int jz, int tmp, int same_jz){
	if(jz > n){
		
		return;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] < a[jz]){
			int cur = a[jz]-a[i]; //分配给他的余额  
			if(tmp >= cur){
				tmp -= cur; //余额减少  
				same_jz++; 
			}
		}else if(a[i] == a[jz]){
			same_jz++;
		}
	} 
	
	ans = max(ans, same_jz);
	
	dfs(jz+1, m, 0);
	
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,m,0);
	cout << ans;
	return 0;
} 





