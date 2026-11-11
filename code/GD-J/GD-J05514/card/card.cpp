#include <bits/stdc++.h>
using namespace std;
long long n,m,desk_f,a[500002],s[300002];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		int desk[500002];
		map <int,int> g;
		desk_f = 1;
		for (int j = i;j <= n;j++){
			if (g[a[j]]){
				desk_f = g[a[j]]+1;
			}else{
				desk[desk_f] = a[j];
				g[a[j]] = desk_f++;
			}
		}
		for (int j = 1;j < desk_f;j++){
			s[desk[j]]++;
		}
	}
	for (int i = 1;i <= m;i++){
		cout << s[i] << " ";
	}
	return 0;
}
