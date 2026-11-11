#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+901;
long long n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	ans=a[n];
//	for(int i=n-1;i>=n-m+1;i--){
//		ans=(ans & a[i]);
//	}
//	cout << ans;
	cout << a[n-m+1];
	return 0 ;
}
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5+101;
//long long n,m,a[N],ans;
//int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	cin >> n >>m;
//	for(int i=1;i<=n;i++)cin >> a[i];
//	sort(a+1,a+1+n);
//	ans=a[n];
//	for(int i=n-1;i>=n-m+1;i--){
//		ans=(ans & a[i]);
//	}
//	cout << ans;
//	return 0 ;
//}
