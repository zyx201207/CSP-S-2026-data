#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n,m;
int val[N]; 
bool ispl[M];
int table[N];
int firsp[M];
int ans[M];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >>m; 
	for (int i = 1;i<=n;i++) cin >> val[i];
	
	for (int i = 1;i<=n;i++){
		int cnt = 0;
		memset(ispl, false, sizeof(ispl));
		memset(table, 0, sizeof(table));
		memset(firsp, 0, sizeof(firsp));
		for (int j = i;j<=n;j++){
			int rec = val[j];
			if (!ispl[rec]) {
				cnt++;
				table[cnt] = rec;
				ispl[rec] = true;
				firsp[rec] = cnt;
			}else {
				for (int k = firsp[rec] + 1;k <= cnt;k++){
					ispl[table[k]] = false;
					table[k] = 0;
				}
				cnt = firsp[rec];
			}
		}
		for (int k = 1;k<=cnt;k++) ans[table[k]]++;

	}
	for (int i = 1;i<=m;i++) cout << ans[i] << " ";
		 
	fclose(stdin);
	fclose(stdout);
		 
	return 0;
}
