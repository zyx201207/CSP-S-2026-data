#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],ans=1,pre[200010],cnt;
signed main(){
	freopen("and,in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		ans=a[i];
	}
	cout<<ans;
	return 0;
}
