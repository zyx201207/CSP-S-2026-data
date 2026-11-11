//GZ-J00577 六枝特区第二中学 陈鹏旭 
#include <bits/stdc++.h>
using namespace std;
int n, m,num[100010],k,b[100010],c[100010];
int op(int x){
	int num2[100010];
	for(int i = 2; i <= x/2; i++){
		num2[i] = x % 2;
	}
	return 0;
}
void dfs(int y){
	if(k == y + 1){
		for(int i = 0;i<4;i++){
			cout << b[i]
		}
	}
	for(int i = c[k- 1]+1;i<=m;i++){
		d[k] = i;
		dfs(k+1);
	}
}
int main(){
	//froepen("and.in","w",stdin);
	//froepen("and.out","r",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++) cin >> num[i];
	dfs(1)
}
