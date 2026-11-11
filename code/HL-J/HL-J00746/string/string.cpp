
#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5+10;
int n;
int a[N];
char b[N];
bool f;
long long cnt;


int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	f = true;
	
	for(int i = 1; i <= n/2; i++){
		if(a[i] >= 1000000000){
			for(int j = n/2+1; j >= 1; j--){
			if(a[i] == a[j] && b[i] != b[j]){
				cnt += a[i];
				f = false;
			}
		}
		}else{	
			for(int j = n; j >= n/2+1; j--){
				if(a[i] == a[j] && b[i] != b[j]){
					cnt += a[i];
					f = false;
				}
			}
		}
	}
	
	if(f == true){
		cout << 0;
		return 0;	
	}else {
		cout << cnt <<endl;
	}
	
	
	return 0;
}

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/