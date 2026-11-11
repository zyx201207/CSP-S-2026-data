#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxy,num,k[200005],x;
long long w[200005][40];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}if (m == 1){
		long long maxa = 0;
		for (int j = 1;j<=n;j++){
			maxa=max(a[j],maxa);
		}
		cout << maxa;
		return 0;
	}else if (m==n){
		int sum = a[1];
		for (int i = 1;i<=n;i++){
			sum=(sum&a[i]);
		}cout << sum;
		return 0;
	}
	for (int i = 1;i<=n;i++){
		int j = 1;
		x = a[i];
		while (x){
			w[i][j]=x%2;
			x/=2;
			j++;
		}
	}
	for (int i = 40;i>=1;i--){
		num = 0;
		for (int j = i;j<=n;j++){
			if (w[j][i] == 1){
				num++;
			}
		}
		if (num>=m){
			maxy=i+1;
			break;
		}
	}
	if (maxy == 0){
		return 0;
	}
	int o = 0;
	for (int i = 1;i<=n;i++){
		if (w[i][maxy]==1){
			o++;
			k[o]=a[i];
		}
	}
	sort(k+1,k+o+1);
	int sum = k[1];
	for (int i = 1;i<=m;i++){
		sum = (sum & k[i]);
	}
	cout << sum;
	return 0;
}
