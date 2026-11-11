#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,int> mp;
int a[200005];
int main(){
	freopen("and.in",r);
	freopen("and.out",w);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
