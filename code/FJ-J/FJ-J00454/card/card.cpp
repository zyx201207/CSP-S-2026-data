#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200050];
int ans[100050];
int num[100050];
vector<int> h[200050];
int main(){
	freopen("F:\\cspj\\down\\card\\card3.in", "r", stdin);
	freopen("F:\\cspj\\down\\card\\card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		h[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		memset(num, 0, sizeof(num));
		for(int j = i; j <= n; j++){
//			cout << "i = " << i << ", j = " << j << '\n'; 
//			cout <<"aj = " << a[j] << ", num[a[j]] = " << num[a[j]] << '\n';
			if(num[a[j]] + 1 < h[a[j]].size()){
//				cout <<"1\n";
				j = h[a[j]][++num[a[j]]] - 1;
			}
			else{
				ans[a[j]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
/*

*/

