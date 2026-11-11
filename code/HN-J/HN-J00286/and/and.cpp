#include<bits/stdc++.h>
#define Year2026 ios::sync_with_stdio(0);
#define October cin.tie(0),
#define thirtyone cout.tie(0);
#define fori for(int i = 1; i <= n; i ++)
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N];
/**f[i][j]:当选了i个数，选到第j个的时候，&的最大值
	function :
	    f[i][j] : max f[i][j-1] , f[i-1][j-1] & a[i]
	start :
		f[0][1 -> n] : a[i]
	end :
		f[m][n]  X
	递归 dfs(x,y) 选到 x 个，选了 y 个 
**/
int dfs(int x,int y){
	if(y == m) return a[x];
	if(x >= n && y != m) return -1;
	int q = dfs(x + 1,y + 1);
	int p = dfs(x + 1,y);
	q &= a[x];
	return max(q,p);
}
int main(){
	Year2026 October thirtyone
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	fori cin >> a[i];
	int maxn = -1;
	fori maxn = max(maxn,a[i]);
//	fori cout << a[i] << " ";
    if(m == n){
    	int res = a[1];
    	for(int i = 2; i <= n; i ++)res &= a[i];
    	cout << a[n];
	}
	else if(m == 1){
		cout << maxn;
	}else if(maxn < 4){
		int a00,a01,a10,a11;
		a00 = a01 = a10 = a11 = 0;
		fori{
			if(a[i] == 0) a00++; 
			if(a[i] == 1) a01++; 
			if(a[i] == 2) a10++; 
			if(a[i] == 3) a11++; 
		} 
		if(m > a11) m-= a11;
		else {cout << 3;return 0;}
		if(m > a10) m -= a10;
		else {cout << 2;return 0;}
		cout << 0;
		return 0;
	}
	else cout << dfs(0,0);
	return 0;
} 
