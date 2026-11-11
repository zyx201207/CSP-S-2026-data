#include <bits/stdc++.h>
using namespace std;
int x[1000000], y[1000000], z[1000000];
int count(int s, int t){
	int i=1, j=1, cnt=0;
	while (s>0){
		x[i] = s%2;
		s/=2;
		i++;
	}
	while (t>0){
		y[j] = t%2;
		t/=2;
		j++;
	}
	for (int l=1; l<=1000000; l++){
		z[l] = x[l] && y[l];
	}
	for (int d=1; d<=1000000; d++){
		if (z[d]==1){
			cnt += pow(2, d-1);
		}
	}
	return cnt;
}

int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l=1;
	int a[1000000], b[1000000], c[1000000];
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	sort(a,a+n+1);
	
	for (int i=n; i>=n-m+1; i--){
		b[l] = a[i];
		l++;
	}
	c[1] = count(b[1], b[2]);
	for (int i=2; i<m; i++){
		c[i] = count(c[i-1], b[i+1]);
	}
	cout << c[m-1];
	
	return 0;
}
