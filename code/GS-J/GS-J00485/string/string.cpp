#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000001;
int a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, sum = 0;
	string c;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> c;
		sum += a[i];
	}
	cout << sum / 2;
	return 0;
}
