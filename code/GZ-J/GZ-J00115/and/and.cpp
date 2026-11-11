//准考证号：GZ-J00115学校：六盘水市第二十四中学姓名：周启明
#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005],ma;
bool f[200005];

void dfs(long long x,long long y,long long z){
	if (x == m){
		ma = max(ma,z);
		return ;
	}if (y > n){
		return ;
	}for (int i = y;i <= n;i++){
		f[i] = 1;
		dfs(x + 1,i + 1,z & a[i]);
		f[i] = 0;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (m == n){
		ma = a[1];
		for (int i = 2;i <= n;i++){
			ma &= a[i];
		}cout << ma;
		return 0;
	}if (m == 1){
		for (int i = 1;i <= n;i++){
			ma = max (ma,a[i]);
		}cout << ma;
		return 0;
	}
	for (int i = 1;i <= n;i++){
		f[i] = 1;
		dfs(1,i + 1,a[i]);
		a[i] = 0;
	}cout << ma;
	return 0;
}   
