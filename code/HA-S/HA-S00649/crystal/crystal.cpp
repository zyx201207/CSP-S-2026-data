#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n;
	cin >> m;
	int a[500008];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long e[500008];
	long long c;
	long long d;
	long long p;
	long long b;
	for(long long i = 1;i <= n - 2;i++){
		p = m;
		b = 1;
		for(long long j = i;j <= n - 1;j++){
			c = a[j + 1] - a[j];
			d = c * b;
			p -= d;
			if(p < 0){
				e[i] = b;
				break;	
			}
			b++;
		}
	}
	sort(e + 1,e + n + 1);
	cout << e[n];
	return 0;
}
