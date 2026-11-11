#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j= 1; j <= n; j++){
			if(a[i] < a[j]){
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
	int num [50005] ={0};
	
	for(int i = n; i > 1; i--){
		long long cnt = 0;
		num[i] = 1;
		for(int j = i-1; j >= 1; j--){
			cnt += a[i]-a[j];
			if(m-cnt>=0){//每步走完的步数 
				num[i]++;
			}else{
				
				break;
			}
		}
	}
	int max_value = 0;
	for(int i = 1; i <= n; i++){
		if(num[i] > max_value){
			max_value = num[i];
		}
	}
	cout << max_value << endl;
	return 0;
}


