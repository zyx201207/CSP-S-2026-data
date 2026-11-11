//GZ-J00314   陈彧山 	遵义市新蒲新区滨湖中学
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	cout << a[m];
	return 0;
}
