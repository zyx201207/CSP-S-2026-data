#include<bits/stdc++.h>
using namespace std;

long long n , m , a[200010] , c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,greater<int>());
	for(long long i = 1;i <= m;i ++){
		if(i == 1){
			c = a[1];
		}
		c &= a[i];
	}
	cout << c;
	return 0;
}
