#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[100007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n);
	ans=a[n];
	for(int i=1;i<m;i++){
		ans=(ans&a[n-i]);
	}
	cout<<ans;
	return 0;
}
