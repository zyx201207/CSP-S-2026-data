#include<bits/stdc++.h>
using namespace std;
int n,m,b=1e9;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;i++){
		b=min(b,a[i]);
	}
	cout<<b;
	return 0;
}
