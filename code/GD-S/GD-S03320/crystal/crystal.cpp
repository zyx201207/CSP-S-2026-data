#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c,d,p;
	cin >> n >> m;
	int a[n];
	int b[n];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = 0;
	}
	sort(a+1,a+n+1);
	int sum = 0;
	for(int i = 2;i <= n;i++){
		c=0;
		d=0;
		for(int j = 1;j <= i;j++){
			b[i] += a[i] - a[j];
		}
		if(b[i]<m){
			c = m - sum;
			d = m - b[i];
		}
		if(c > d){
			sum = b[i];
			p = i+1;
		}
	}
	cout << p;

	return 0;
} 

