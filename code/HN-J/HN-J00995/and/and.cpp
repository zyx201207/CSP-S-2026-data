#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010],ans;
	cin>>n>>m;
	for(int i=1;i<n+1;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n]&a[n-1];
	cout<<ans;
	return 0;
}
