#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e5 + 5;
int n, m, a[maxn], ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++){
		int d[maxn], card[maxm], s[maxn];
		memset(d, 0, sizeof d);
		memset(card, 0, sizeof card);
		
		for(int j = i; j <= n; j++){
			d[j]++;
			d[j + 1]--;
			if(card[a[j]] == 0) card[a[j]] = j;
			else {
				d[card[a[j]]]--;
				d[j]++;
			}
		}
		
		for(int j = 1; j <= n; j++){
			s[j] = s[j - 1] + d[j];
			if(s[j] > 0) ans[a[j]]++;
		}
		
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0; 
} 
