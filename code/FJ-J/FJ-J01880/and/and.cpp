#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[10000005];
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long r = a[1];
	for(long long i = 2;i <= m;i++){
		r = r&a[i];
	}
	cout << r;
	return 0;
}
