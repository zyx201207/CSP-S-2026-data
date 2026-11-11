#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],ans=max(ans,a[i]);
	cout<<ans<<"\n";
	return 0;
}
