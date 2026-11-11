#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	int a[t];
	int tmp = 0;
	for(int z = 0;z < t;z++){
		int n;
		long long d;
		cin >> n >> d;
		
		long long arr[n];
		int x = n;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] - d > arr[i - 1]){
				x--;
			}
		}
		
		int ans = 0;
		for(int i = 0;i < x;i++){
			for(int j = i + 1;j < x;j++){
				long long way = arr[j] - arr[i];
				if(way == 3 && d == 2){
					ans++;
				}
				if(way > d && way - 1 < d){
					ans++;
				}
			}
		}
		
		a[tmp] = ans;
		tmp++;
	}
	
	for(int i = 0;i < tmp;i++){
		cout << a[i] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
