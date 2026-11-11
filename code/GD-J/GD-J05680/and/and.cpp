#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
int a[N], f[N][N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[i][1] = a[i];
	}
	for (int i = 2; i <= n; i++){
		for (int j = m; j >= 2; j--){
			f[i][j] = max(f[i][j], (f[i-1][j-1])&a[i]);
		}
	}
	cout << f[n][m];
	return 0;
}
//以下为正解代码，想不出来力竭了，以上为一个疑似背包的只能过第一个样例的也算作暴力代码 
//const int N = 2e5+10;
//struct se{
//	short num[35];
//}f[N];
//int a[N];
//void tur(int x){//将a的第x项转为二进制 
//	int b[35], n=0, y=x;
//	while (y){
//		f[x].num[n++]=y%2;
//		y /= 2;
//	}
//}
//bool j(se x, se y){
//	for (int i = 29; i >= 0; i++){
//		if (x.num[i]!=y.num[i])return x.num[i]>y.num[i];
//	}
//	return false;
//}
//bool com(vector<int> v, int n, int m, int k){
//	
//}
//int n, m;
//int main(){
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//		tur(i);
//	}
//	sort(f+1, f+n+1, j);
//	for (int i = 0; i <= 30; i++){
//		int cnt = 0;
//		vector<int> v;
//		for (int j = 1; j <= n; j++){
//			if (f[i].num[j]){
//				cnt++;
//				v.push_back(j);
//			}
//		}
//		if(cnt>=m){
//			if (cnt == m){
//				int ans = v[0];
//				for (int i = 1; i < cnt; i++)ans = (ans&v[i]);
//				cout << ans;
//				return 0;
//			}
//			else{
//				
//			}
//		}
//	}
//	return 0;
//}
