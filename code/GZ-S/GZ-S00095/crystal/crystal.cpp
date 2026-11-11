//GZ-S00095 遵义市第十二中学 戴沉鑫 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, a[50005], b[50005], cnt = 0, ans = 0, daan, hl = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt += a[i];
	}
	daan = ceil(cnt / n);
	while(daan){
		for(int i = 1; i <= n; i++){
			if(a[i] <= daan){
				hl += daan - a[i];
			}
		}
		if(hl <= m){
			for(int i = 1; i <= n; i++){
				if(a[i] <= daan){
					ans++;
				}
			}
			break;
		}
		else daan -= 1;
	}
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

