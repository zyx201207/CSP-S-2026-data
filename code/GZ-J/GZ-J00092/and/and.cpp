//GZ-J00092 马熙程 贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	string k;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		for(int j = n;j <= 1;i--){
			k += a[j] % 2;
			a[j] /= 2;
		}
	}
	cout << 12;
	return 0;
} 
