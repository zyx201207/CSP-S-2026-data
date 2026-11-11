#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int b[2];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n,cmp);
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i+1]){
			cout << (a[i] & a[i+1]);
			return 0;
		}
	}
	int k = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] % 2 == 1 && cnt < 2){
			b[k] = a[i];
			k++;	
		}
	}
	if(k < 2){
		cout << (a[1] & a[2]);
	}else{
		cout << (b[1] & b[2]);
	}
	return 0;
}
