//六盘水市第二十四中学 廖奕然 GZ-J00598 
#include <bits/stdc++.h>
using namespace std;
int a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	int result = a[1];
	for(int i = 2;i <= m;i++){
		result = result & a[i];
	}
	cout << result;
	return 0;
}
