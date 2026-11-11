//GZ-S00253 ½¯Ò»³½ 
#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int ma, k, cnt = 1;
bool flag;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1] >> a[2];
	int cha = a[2] - a[1];
	for(int i = 3; i <= n; i++){
		cin >> a[i];
		if(a[i] - a[i-1] != cha) flag = 1;
	}
	if(!flag) {
		k = cha;
		while(n > 1 && m >= k*cha){
			m -= cha;
			cnt++;
			k++;
			n--;
		}
		cout << cnt;
		return 0;
	}
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++){
		k = i, cnt = 1;
		int t = m;
		while(--k){
			if(t >= a[i] - a[k]){
				t -= a[i] - a[k];
				cnt++;
			}else break;
		}
		ma = max(ma, cnt);
	}
	cout << ma;
	return 0;
}
