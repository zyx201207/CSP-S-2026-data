#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			maxx=max(a[i]&a[i+1],maxx);
		}
	}
	cout<<maxx;
	return 0;
}
