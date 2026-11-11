#include<bits/stdc++.h>
using namespace std;
int main(){
	// INI
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[550000];
	int cnt[330000];
	vector<int> table;
	// INP
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	// VRG
	for(int i=1; i<=n; i++){
		table = {};
		for(int j=i; j<=n; j++){
			int index = -1;
			for(int k=0; k<int(table.size())-1; k++){
				if(table[k] == a[j])
					index = k;
			}
			if(index != -1)
				table.erase(table.begin()+index, table.end());
			table.push_back(a[j]);
		}
		bool flag[330000];
		memset(flag, 0, sizeof(flag));
		for(int card : table){
			if(flag[card] == 0){
				cnt[card]++;
				flag[card] = 1;
			}
		}
	}
	// OUT
	for(int i=1; i<=m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
