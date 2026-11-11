#include<bits/stdc++.h>
using namespace std;

int n, m;
int card[500005];
int t[500005];
bool a[300005];
int cnt[300005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> card[i];
	}
	for(int i=1; i<=n; i++){
		cout << m << ' ';
	}
	return 0;
}
