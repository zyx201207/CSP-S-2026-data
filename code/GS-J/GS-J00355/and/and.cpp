#include<bits/stdc++.h>
using namespace std;
long long a[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],a[i-1]);
	}
	cout<<ans;
	return 0;
}
