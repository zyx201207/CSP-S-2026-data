//GZ-J00178 观山湖中学 陈辰 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int ans[N];
void solve(){
	int n,m;
	cin >>n>>m;
	for (int i = 1,a;i <= n;i++){
		cin >> a;
		ans[a]=i;
	}
	for (int i = 1;i <= m;i++){
		cout <<ans[i]<<"　";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin >>T;
	while(T--){
		solve();
	}
	return 0;
}
