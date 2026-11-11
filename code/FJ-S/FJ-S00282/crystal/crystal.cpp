#include<bits/stdc++.h>
using namespace std;

int n;//n:能量水晶数量
long long m;// m:增加次数上线
long long a[500005] = {};
long long pre[500005] = {};//pre[i][j] -> 水晶i到水晶j的差值 

void tepan(){
	long long ans = 0;
	ans = m / (a[2] - a[1]);
	cout << ans;
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 3; i <= n; i++){
		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])break;
		tepan();
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			pre[j] = pre[j] + (a[j] - a[i]);
		}
	}
	int i = n;
	while(pre[i] > m){
		i--;
	}
	
	cout << i;
	
	return 0;
}
