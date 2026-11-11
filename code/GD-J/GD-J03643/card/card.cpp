#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

int n,m;
int a[N];
int id[N];
int ans[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;++i) cin >> a[i];
	
	
	if (n <= 5000){
		for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j) id[j] = 0;
		int r = 1;
		int card[N];
		
		for (int j=i;j<=n;++j){
			if (id[a[j]] == 0 || id[a[j]] >= r || card[id[a[j]]] != a[j]){
				card[r] = a[j];
				id[a[j]] = r++;
			}
				else{
					r = id[a[j]]+1;
				}
			}
		
			for (int j=1;j<r;++j) ans[card[j]]++;
		}
	
		for (int i=1;i<=m;++i) cout << ans[i] << ' ';
	}
	else{
		for (int i=1;i<=n;++i){
			if (a[i] != a[i+1]) cout << i << ' ';
		}
	}
	
	
	
	
	
	return 0;
} 
