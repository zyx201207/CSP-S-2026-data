#include<bits/stdc++.h>
using namespace std;
int a[200006];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int s=a[1];
	for(i=2;i<=m;i++){
		s&=a[i];
	}
	cout<<s;
	return 0;
} 
