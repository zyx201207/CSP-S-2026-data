#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	//int ans1;
	long long a[100010];
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		if(a[1]==a[n]){
			cout << n;
			exit(0);
		}
	}
	
	/*int b[100010],ans;
	for(int i = 1;i<n;i++){
		b[i] = a[n] - a[i];
		ans+=b[i];
	}
	if(ans <= m){
		cout << n;
	}*/
	int c[100010],bb[100010];
	c[1] = 0;
	for(int i = 2;i<n;i++){
		bb[i] = a[i+1] - a[i];
		for(int j = 2;j<=n;j++){
			c[j] = (j-1)*bb[j-1] + c[j-1];
		}
	}
	for(int k = n;k>=1;k--){
		if(c[k]<=m){
			cout << k;
			break;
		}	
	}
	return 0;
}
