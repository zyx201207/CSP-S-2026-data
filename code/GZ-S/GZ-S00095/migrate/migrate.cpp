//GZ-S00095 遵义市第十二中学 戴沉鑫
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t, n, d, a[200006], cnt[200006], k = 1;
	cin >> c >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = n; i >= 1; i++){
			if(d > a[i] - a[i - 1]){
				d -= a[i] - a[i - 1];
				cnt[k]++;
			}else k++;
		}
	}
	cout << k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
