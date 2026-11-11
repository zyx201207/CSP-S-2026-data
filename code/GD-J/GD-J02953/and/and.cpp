#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a+1,a+n+1);
		cout << a[n];
	}
	int max = -1;
	for(int i=1;i<=n-m+1;i++){
		int z = a[i];
		for(int j=i+1;j<=i+m-1;j++){
			z = z&a[j];
		}
		if(z>max){
			max = z;
		}
	}
	cout << max;
	return 0;
}
