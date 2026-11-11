#include <bits/stdc++.h>
using namespace std;
long long  n,a[20000005],ans,m;
bool cmp(int a,int b){
	return a < b;
	}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long i;
	for(i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n,cmp);
	ans = a[1];
	for(i = 2;i <= m;i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
