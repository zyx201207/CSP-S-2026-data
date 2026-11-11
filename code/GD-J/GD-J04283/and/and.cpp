#include<bits/stdc++.h>
using namespace std;
#define int long long
const int st = 1073741823;
struct number{
	int a;
	int opos;
}num[200010];
int bx[40];
int n,m;
bool cmp(number x,number y){
	return x.opos < y.opos;
}
int ans = 0;
void dfs(int u,int sm,int x){
	if(x <= ans) return ;
	if(sm == m){
		ans = x;
		return ;
	}
	if(m-sm > n-u) return ;
//	cout << u << ' ' << sm << ' ' << x << '\n';
	dfs(u+1,sm+1,(x&num[u].a));
	dfs(u+1,sm,x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		num[i].a = x;
		num[i].opos = -1;
		int cnt = 0;
		for(int i = 0;i <= 30;i ++){
			bx[i] = 0;
		}
		while(x != 0){
			bx[cnt++] = x % 2;
			x /= 2;
		}
		for(int i = 30;i >= 0;i--){
			if(bx[i] == 1){
				num[i].opos = i;
				break;
			}
		}
	}
	sort(num+1,num+n+1,cmp);
	dfs(1,0,st);
	cout << ans << '\n';
	return 0;
}
