#include<bits/stdc++.h>//g++ 1.cpp -o exe -Wall -O2 -std=c++14
#define int long long//rp++
using namespace std;//为什么T1 卡我这么久qwq 还拿不满QWQ 
int n;
const int N = 5e5+5;
int m;
int a[N],w[N];
int ans;
int sum;
int mymax = LLONG_MIN;
bool flag1 = 1,flag2 = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int d = a[2]-a[1];
	for(int i = 2;i <= n;i++){
		w[i] = a[i]-a[i-1];
		if(w[i] != i) flag1 = 0;
		if(w[i] != d) flag2 = 0;
	}
	if(flag1){
		ans = 1,sum = 1;
		if(m < ans){
			cout << 1;
			return 0;
		}
		for(int i = 2;i <= n;i++){
			if(m >= ans+i){
				ans += i;
				m -= ans;
				sum++;
			}
		}
		cout << sum;
		return 0; 
	}
	if(flag2){
		ans = 0,sum = 1;
		if(d > m){
			cout << 1;
			return 0;
		}
		for(int i = 2;i <= n;i++){
			if(m >= ans+(d*sum)){
				ans += (d*sum);
				m -= ans;
				sum++;
			}
		}
		cout << sum;
		return 0;
	}
	//sort(w+1,w+n+1);
	for(int i = 2;i <= n;i++){
		sum = 1;
		int mm = m;
		for(int j = i;j <= n;j++){
			if(w[j]*sum <= mm){
				mm -= w[j]*sum;
				sum++;
			}
		}
		mymax = max(mymax,sum);
	}
	cout << mymax;
	return 0;
}
