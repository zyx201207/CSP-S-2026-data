#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=i;j<j+m;j++) if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
	cout<<ans;
	return 0;
}
