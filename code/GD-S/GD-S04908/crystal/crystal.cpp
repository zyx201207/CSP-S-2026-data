#include<iostream>
using namespace std;

long long a[500050];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum = 1,ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(i != n && a[i] > a[i+1]){
			int x = a[i];
			a[i] = a [i+1];
			a[i+1] = x;
			i-=2;
		}
	}
	for(int i = 1; i <= n; i++){
		int mm = m;
		sum = 0;
		for(int j = i; j >= 1; j--){
			if(a[i] - a[j] <= mm){
				sum++;
				mm = mm - a[i] + a[j];
			}
		}
		if(sum >= ans){
			ans = sum;
		}
	}
	cout << ans;
	return 0;
} 
