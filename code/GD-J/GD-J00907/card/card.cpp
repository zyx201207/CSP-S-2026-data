#include<bits/stdc++.h>
using namespace std;

int n, m, a[200010], b[200010];
int find1(int x){
	bool f = false;
	for(int i = 1; i <= n; i ++){
		if(f && (a[i] != x)){
			return (i - 1);
		}
		if(a[i] == x) f = true;
	}
	return n;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	bool field = true;
	for(int i = 1; i <= n; i ++){
		if(a[i] != b[i]){
			field = false;
		}
	}
	if(field){
		for(int i = 1; i < m; i ++){
			int k = find1(i);
			cout << k << ' ';
		}
		cout << n;
	}
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
