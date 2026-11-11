#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 0;i < t;i++){
		int num,max,ans = 0;
		cin >> num >> max;
		int a[num];
		for(int j = 0;j < num;j++){
			cin >> a[j];
		}
		bool flag = 1;
		for(int j = 1;j < num;j++){
			if(a[j] - a[j - 1] > max){
				num = j - 1;
				flag = 0;
				break;
			}
		}
		if(flag) num--;
		for(int j = a[0];j <= a[num];j++){
			for(int z = j + max + 1;z <= a[num];z += max + 1){
				if(z % (max + 1) == j % (max + 1)) ans++;
			}
		}
		if(i < t - 1){
			cout << ans << '\n';
		}else{
			cout << ans;
		}
	}
	return 0;
}

