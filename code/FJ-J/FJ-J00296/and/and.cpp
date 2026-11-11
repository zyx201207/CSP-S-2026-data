#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int n,m;
	cin >> n >> m;
	int b;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		if(i == 1){
			b = a[i];
			continue;
		}
		if(i > m){
			break;
		}
		else{
		    b = b & a[i];	
		}
	}
	cout << b;
	return 0;
}
