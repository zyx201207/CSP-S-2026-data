#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200005];
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i];
	}
	sort(a,a+n);
	int ans=a[0];
	for(int i=1; i<m; i++){
		ans&=a[i];
	}
	cout << ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
