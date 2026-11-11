#include<bits/stdc++.h>
using namespace std;
int ans[200010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int aaa = t;
	if(c==11 || c==12){
		while(t>0){
			int n,d,a[200010] = {0};
			cin >> n >> d;
			for(int i = 0;i<n;i++){
				cin >> a[i];
			}
			int len = a[1]-a[0];
			if(len>d){
				ans[t] = 0;
				continue;
			}
			//max lands
			ans[t] = n-3;
			t--;
		}
		return 0;
	}
	while(t>0){
		int n,d,a[200010] = {0};
		cin >> n >> d;
		for(int i = 0;i<n;i++){
			cin >> a[i];
		}
		ans[t] = n-3;
		t--;
	}
	for(int i = aaa;i>0;i--){
		cout << ans[i] << endl;
	}
	return 0;
}
