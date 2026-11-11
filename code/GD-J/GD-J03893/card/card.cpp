#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
int a[N], b[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		vector<int> v;
		for(int j = i; j <= n; j++){
			auto it = find(v.begin(), v.end(), a[j]);
			if (it == v.end() || *it != a[j])
				v.push_back(a[j]);
			else{
				while(v.size() > it - v.begin())
					v.pop_back();
				v.push_back(a[j]);
			}
		}
		for(int x : v){
			b[x]++;
		}
	}
	for(int i = 1; i <= m; i++)
		cout << b[i] << ' ';
	return 0;
}

