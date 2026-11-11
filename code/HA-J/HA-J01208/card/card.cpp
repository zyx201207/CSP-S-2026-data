#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	bool flag = 0;
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] <= a[i+1]){
			flag = 1;
		}else flag = 0;
	}
	if(flag = 1){
		for(int i = 1; i <= m; i++){
			cout << n << " ";
		}
	}
	return 0;
}
