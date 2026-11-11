#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(n > 60000){
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a + 1,a + n + 1);
		for(int i = 1;i <= n;i++){
			s[i] += s[i - 1] + a[i];
		}
		for(int i = 2;i <= n;i++){
			for(int j = 1;j <= n - i;j++){
//				cout << a[i + j - 1] << " " << i << " " << s[j + i - 1] - s[j - 1] << endl;
				if((a[j + i - 1] * i) - (s[j + i - 1] - s[j - 1]) <= m){
					ans = i;
					break;
				}
			}
		}
		cout << ans;
	}else {
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a + 1,a + n + 1);
		for(int i = 1;i <= n;i++){
			s[i] += s[i - 1] + a[i];
		}
		for(int i = 2;i <= n;i++){
			for(int j = 1;j <= n - i;j++){
//			cout << a[i + j - 1] << " " << i << " " << s[j + i - 1] - s[j - 1] << endl;
				if((a[j + i - 1] * i) - (s[j + i - 1] - s[j - 1]) <= m){
					ans = i;
					break;
				}
			}
		}
		cout << ans;
	}
	return 0;
} 
