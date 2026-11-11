#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n],b[m] = {0};
	vector<int> table;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			int h = table.size() + 1;
			for(int k = 0;k < table.size();k++) if(table[k] == a[j]) h = k;
			if(h < table.size()) table.erase(table.begin(),table.begin() + h);
			table.push_back(a[j]);
		}
		int hum[m] = {0};
		for(int j = 0;j < table.size();j++) hum[table[j] - 1]++;
		for(int j = 0;j < m;j++) if(hum[j] > 0) b[j]++;
	}
	for(int i = 0;i < m;i++) cout << b[i] << (i == m - 1 ? "\n" : " ");
	return 0;
}
