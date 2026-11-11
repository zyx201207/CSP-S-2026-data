#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5000 + 5;
int c,T,n,k,a[N],nxt[N],ans;
int chk(int x,int y){
	vector<int>g;
	while (x < y){
		g.push_back(nxt[x]);
		if (x == nxt[x]) return 0;
		x = nxt[x];
//		cout << x<< ' ';
	}
//	cout<<endl;
	int cnt = 0;
	for (auto i : g){
		if (i >= y) continue;
		if (nxt[i-1] == min(nxt[i],y)){
//			cout << x << " " << y << ' ' << i << endl;
			++cnt;
		} 
	}
	return (cnt == 1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--){
		ans = 0;
		cin >> n >> k;
		for (int i = 1;i <= n;i++) cin >> a[i];
		for (int i = 1;i <= n;i++){
			for (int j = i;j <= n;j++){
				if (a[j]-a[i]<=k) nxt[i] = j;
				else break;
			}
		}
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
//				cout<<endl;
//				if (chk(i,j))cout<<"yes"<<endl;
//				cout<<endl;
//				cout << i <<"    " << j  << endl;
				ans += chk(i,j);
			}
		}
		cout << ans << '\n';
//		chk(1,4);
//		cout << nxt[3]<<endl;
//cout << chk(1,5) << endl;
	}
	return 0;
}



