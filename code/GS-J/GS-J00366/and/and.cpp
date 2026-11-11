#include<bits/stdc++.h>
using namespace std;
int a[1000025],v[1000025];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = n - m + 1;i <= n;i++)
		v[i] = min(a[i],a[i + 1]);
	cout << v[n - m + 1];
	return 0;
}
