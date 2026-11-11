#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,p;
int be,en,ans;
int a[500005];
int to[5505][5505]; 
void dfs(int b,int fa,int an){
	if (b == en || an > ans){
		ans = min(ans,an);
		return ;
	}
	else{
		for (int i = 1;i <= i+m;i++){
			if (to[b][i]!=0 && i!=fa){
				dfs(i,b,an+to[b][i]);
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in ","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++){
		cin >> p;
		int x,y;
		for (int j = 1;j <= p;j++){
			cin >> x >> y;
			to[i+m][x] = y;
			to[x][i+m] = y;
		}
	}
	while (q--){
		cin >> be >> en;
		if (be == en){
			ans = 0;
			continue;
		}
		ans = 1e9;
		dfs(be,-1,a[be]+a[en]);
		cout << ans << endl;
	}
	return 0;
}

