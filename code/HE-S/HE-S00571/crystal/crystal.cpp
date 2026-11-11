#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	int b = a[1] - a[0];
	cout << n - b;
	return 0;
}
