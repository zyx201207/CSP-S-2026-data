#include<bits/stdc++.h>
using namespace std;
int maxx = -1,n,m,a[200005],now;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			now = a[i] & a[j];
			maxx = max(maxx,now);
		}
	}
	cout << maxx;
	return 0;
}