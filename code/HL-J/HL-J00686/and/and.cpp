#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n,m,a[100005],n1,m1,num = 1,Maxx = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	n1 = n;
	m1 = m;
	for (int i = 1; i < m; i++){
		n *= (n1 - i);
		m *= (m1 - i);
	}
	while (m!=0){
		for (int i = num; i < n; i++){
			if (Maxx < (a[num] & a[i+1])){
				Maxx = (a[num] & a[i+1]);
			}
		}
		m--;
		num++;
	}
	cout << Maxx;
	return 0;
}
