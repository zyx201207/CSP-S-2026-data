#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, k, q;
	vector<int> a,p,t,flag;
	
	scanf("%d%d", &n, &m);
	for(int z = 0; z < m; z++)
	p.push_back(0);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		a.push_back(k);
	}
	for(int i = 0; i < n; i++){
		for (int q = i; q < n; q++){
			for(int j = 0; j < t.size(); j++)
				if(t[j] == a[q])
					for(int l = j; l < t.size(); l++)
						t[l] = 0;
			t.push_back(a[q]);
		}
		flag.push_back(1);
		for(int z = 0; z < m; z++)
			flag.push_back(0);
		for(int q = 0; q < t.size(); q++)
			if(flag[t[q]] == 0) {
				p[t[q]]++;
				flag[t[q]] = 1;
			}
		t.clear();
		flag.clear();
	}
	for(int z = 1; z <= m; z++)
		printf("%d ", p[z]);
	return 0;
}
