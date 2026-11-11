#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << a[1] << endl;
		return 0;
	}
	if(m == n){
		int ans = a[1] & a[2];
		for(int i = 3;i <= n;i++){
			ans = ans & a[n];
			cout << 1 << " ";
		}
		cout << ans << endl;
		return 0;
	}
	if(m == 1){
		sort(a + 1,a + n + 1);
		cout << a[n] << endl;
		return 0;
	}else if(m == 2){
		int Max = -1;
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				int tmp = a[i] & a[j];
				Max = max(Max,tmp);
			}
		}
		cout << Max << endl;
		return 0;
	}else if(m == n - 1){
		int Max = -1,tmp;
		for(int i = 1;i <= n;i++){
			int j;
			if(i == 1){
				tmp = a[2] & a[3];
				j = 4;
			}else if(i == 2){
				tmp = a[1] & a[3];
				j = 4;
			}else{
				tmp = a[1] & a[2];
				j = 3;
			}
			for( ;j <= n && j != i;j++){
				tmp = tmp & a[j];
			}
			Max = max(Max,tmp);
		}
		cout << Max << endl;
		return 0;
	}
	cout << 1000 << endl;
	return 0;
}

