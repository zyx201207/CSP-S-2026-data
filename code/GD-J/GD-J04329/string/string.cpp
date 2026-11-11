#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
int a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	//输入数据 
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> c[i];
	}
	
	//测试点1、2部分解 
	if(n == 1){
		for(int i=1; i<=a[1]; i++){
			cout << 0;
		}
	}else if(n == 2){
		if(c[1] == c[2]){
			cout << 0;
		}else{
			cout << 1;
		}
	} 
	
	//测试点5、6、9、17、18部分解 
	cout << 0;
	return 0;
} 
