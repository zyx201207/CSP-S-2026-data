#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5, M = 5e3 + 5;
int n, m, a[N], p[N], ans[N];
vector<int> cali;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}	
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(p[a[j]]){
				while(cali.back() != a[j]){
					p[cali.back()] = 0;
					cali.pop_back();
				}
				cali.pop_back();
			}
			cali.push_back(a[j]);
			p[a[j]] = 1;
		}
		for(int j = 1;j <= m;j++){
			if(p[j]) ans[j]++;
		}
		while(!cali.empty()) cali.pop_back();
		memset(p, 0, sizeof(p));
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	} 
	return 0;
}

