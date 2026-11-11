#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
int n,m;
int a[200001];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=n;
	ans=a[n];
	for(int i=1;i<=m-1;i++){
		ans=ans&a[--cnt];
	}
	cout<<ans;
	return 0;
}
