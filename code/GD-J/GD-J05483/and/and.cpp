#include <bits/stdc++.h>
using namespace std;
long long a[200005],m,n,ans,maxn,p,p1,p2;
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	ans = a[1] & a[2];
	for (int i = 2;i < n;i++){
		for (int j = i + 1;j <= n;j++){
			if ((a[i] & a[j]) > maxn){
				maxn = a[i] & a[j];
				p1 = i;
				p2 = j;
			}
		}
	}
	ans = maxn;
	b[p1] = true;
	b[p2] = true;
	m--;
	while(m--){
		int basic;
		for (int i = 1;i <= n;i++){
			if (b[i] == 0){
				basic = a[i];
				p = i;
				break;
			}
		}
		for (int i = p;i <= n;i++){
			if (b[i])
				continue;
			if ((basic & a[i]) > maxn){
				maxn = basic & a[i];
				p = i;
			}
		}
		b[p] = true;
		ans = ans & a[p];
	}
	cout << ans;
	return 0;
}
