#include <bits/stdc++.h>
using namespace std;
int n,m;
int max_n = 0;
int a[200005];
void dfs(int step,int num,int x){
	if (step == m){
		max_n = max(max_n,num);
		return;
	}
	if (x > n){
		if (step == m){
			max_n = max(max_n,num);
		}
		return;
	}
	dfs(step + 1,(num & a[x]),x + 1);
	dfs(step,num,x + 1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	int z = 1;
	for (int i = 1;i <= 31;i++)
	{
		z *= 2;
	}
	z -= 1;
	dfs(0,z,1);
	cout << max_n;
}
