#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[200005];
long long ans = 0;
int ABC(int a,int b){
	if (a > b) return a>b;
	else return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,ABC);
	ans = a[1];
	for (int i = 2;i <= m;i++){
		ans = a[i]&ans;
	}
	cout << ans;
	return 0;
}