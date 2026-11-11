#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
const int N = 2e5+100;
int a[N];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long k = 0;
	for(int i = 1; i < n; i++){
		if(a[i]==a[i+1])k = a[i];
	}
	long long sum = 0;
	sort(a+1, a+n+1, cmp);
	sum = a[1];
	for(int i = 1; i <= m; i++){
		sum = sum&a[i];
	}
	cout << max(sum, k);
	return 0; 
}

