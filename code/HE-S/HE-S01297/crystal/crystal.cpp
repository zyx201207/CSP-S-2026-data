#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	int cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	   
	}
	for(int i = 1; i <=n; i++){
		if(a[i] <= a[n/2+1]){
			cnt++;
			
	}
}
	cout << cnt;
	
	

	return 0;
}
