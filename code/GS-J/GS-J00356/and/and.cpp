#include <bits/stdc++.h>
using namespace std;
long long a[2010];
int n,m;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],a[i-1]);
	}
	cout<<ans;
	return 0;
}
