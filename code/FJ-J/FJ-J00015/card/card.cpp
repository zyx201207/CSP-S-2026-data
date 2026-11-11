#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], p[300005], ans[300005], pos;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		pos = 0;
		for(int j = i;j <= n;j++){
			if(p[a[j]] == 0){
				pos++;
				b[pos] = a[j];
				p[a[j]] = pos;
			}
			else{
				for(int k = pos;k > p[a[j]];k--){
					p[b[k]] = 0;
					b[k] = 0;
				}
				pos = p[a[j]];
			}
		}
		for(int j = 1;j <= pos;j++){
			ans[b[j]]++;
			p[b[j]] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i]<<" ";
	}
	return 0;
}
