#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	freopen("and.out","w",stdout);
	cout<<ans;
	return 0;
}
