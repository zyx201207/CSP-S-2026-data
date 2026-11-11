//GZ-J00001 贵阳实验三中 夏上云
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+5;
int a[N];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans = a[1];
	for(int i = 2;i <= m;i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
