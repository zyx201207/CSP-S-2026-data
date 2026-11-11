#include<bits/stdc++.h>
using namespace std;
long long s[35][200005], t[200005], a[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, sum = 0, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		long long temp = a[i];
		int j = 0;
		while(temp){
			s[j][i] = temp % 2;
			temp /= 2;
			j++;
		}
	}
	bool flag = false;
	for(int i = 31;i >= 0;i--){
		int temp1 = 0;
		for(int j = 0;j < n;j++){
			if(s[i][j]){
				temp1++;
				s[34][j] = 1;
			}
		}
		if(temp1 >= m){
			flag = true;
			int q = 0;
			for(int j = 0;j < n;j++){
				if(s[34][j]){
					t[q] = a[j];
					q++;
				}
			}
			sort(t, t + q + 1, greater<long long>());
			for(int j = 0;j < m;j++){
				if(sum == 0){
					sum += t[j];
				}else{
					sum &= t[j];
				}
			}
			break;
		}else{
			for(int j = 0;j < n;j++){
				s[34][j] = 0;
			}
		}
	}
	if(flag){
		cout << sum;
	}else{
		cout << 0;
	}
	return 0;
}
