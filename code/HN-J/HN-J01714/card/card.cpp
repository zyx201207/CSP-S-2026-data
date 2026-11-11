#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005], ax[100005], p, id[100005];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int nax[100005];
		queue<int> x;
		p = 0;
		for(int j = i;j <= n;j++){
			x.push(a[i]);
		}
		for(int j = 1;j <= i;j++){
			if(x.front() == a[j]){
				p = j;
			}
			for(int j = 1;j <= p;j++){
				nax[a[j]] = 1;
			}
			x.push(x.front());
			x.pop();
		}
		
		for(int j = 1;j <= n;j++){
			ax[a[j]] += nax[a[j]];
		}
	}
	int cnt = 0;
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		if(a[i] != a[i - 1]){
			id[i] = a[i]; 
			cnt++;
		}
	}
	for(int i = 1;i <= cnt;i++){
		cout << ax[id[i]] << " ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/

