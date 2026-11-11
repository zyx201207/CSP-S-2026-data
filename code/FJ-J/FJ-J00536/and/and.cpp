#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int m,n;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[n-m+1];
	return 0;
}
