#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],v[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i ++){
		for (int j = i;j <= n;j ++){
			v[j] = a[j];
		}
		for (int j = i;j <= n;j ++){
			for (int k = i;k < j;k ++){
				if (v[k] == v[j]){
					for (int t = k;t < j;t ++){
						v[t] = 0;
					}
					break;
				}
			}
		}
		for (int r = i;r <= n;r ++){
			cnt[ v[r] ] ++;
		}
	}
	for (int  i = 1;i <= m;i ++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
