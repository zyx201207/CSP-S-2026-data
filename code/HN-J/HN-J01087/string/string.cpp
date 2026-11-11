#include <bits/stdc++.h>
using namespace std;
const int N=2*100005;
int n;
int a[N][2];
int b;
char n[N];
int num;
int cnt;

char findn(int it) for (int i=1;i<=n;i++) if ((a[i][0]<=it) and (it <= a[i][1])) return n[i];

int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	a[0][1]=0;
	
	cin >> n;
	for (int i = 1;i<=n;i++){
		cin >> b;
		num+=b;
		a[i][0]=a[i-1][1]+1;
		a[i][1]=a[i-1][1]+b;
		cin >> n[i];
	}
	
	for (int i=1;i<num/2;i++) if (findn(i)!=findn(num-i)) cnt++;
	
	cout << cnt;
	
	return 0;
}
