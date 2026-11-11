#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 1;i <= t;i ++){
		int n,d,cnt = 0;
		cin >> n >> d;
		int a[100010];
		for(int j = 1;j <= n;j ++){
			cin >> a[i];
		}
		for(int j = 1;j <= n;j ++){
			if(a[j])cnt++;
		}
		if(a[1] >= 0)cout << cnt;
		else{
			cout << cnt - 1;
		}
	}
	return 0;
}
