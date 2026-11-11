#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,a[500002];
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(n % 2 == 0){
		cout << n / 2;
	}else{
		cout << n / 2 + 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
