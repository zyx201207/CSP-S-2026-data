#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int a[N] = {};
vector<int>data;
int find(int x) {
	for(int i = 0; i < data.size() ; i ++ ) {
//		cout << a[i] << " " << x  << "der" << '\n';
		if(data[i] == x) {
			return i;
		}
	}
	return -1;
}
int bowl[N] = {};
signed main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	
	for(int i = 1; i <= n;i ++ ) {
		cin >> a[i];
	}
	int ans = 0;
	data.push_back(1);
	//	cout << "test : " << find(1) << '\n';
	//	cout << find(2) << '\n';
	for(int i = 1; i <= n;i ++ ){
		for(int j = i;j <= n; j++){
			int pos = find(a[j]);
			if(pos == -1) data.push_back(a[j]);
			else{
				for(int k = data.size()-1;k >= pos; k--) data.pop_back();
				for(int j = 0; j < data.size() ; j ++ ) {
					cout << data[j] << " "; 
				}
				cout << '\n';
				data.push_back(a[j]);
			}
		}
		
		cout << "i : " << i << " ";
		for(int j = 0; j < data.size() ; j ++ ) {
			bowl[data[j]] ++;
			cout << data[j] << " "; 
		}
		cout << '\n';
		data.clear();
	}

	for(int i = 1 ;i <=m;i ++ ) {
		cout << bowl[i] << ' ';

	}
	return 0;
}

